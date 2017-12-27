#!/bin/bash

# PROJECT_NAME: 修改为项目名称，需要和项目源代码所在文件夹一致;
# COMMAND_LINE: 启动项目的命令，这里写了一般的启动命令，如有需要请修改;

PROJECT_NAME=UpdownServer
COMMAND_LINE="./$PROJECT_NAME.bin -f ./config.ini"

if [ $# -lt 1 ]
then
	echo "必须输入至少一个参数 start|stop|restart|rebuild|show|reload|gcore"
	echo "当输入rebuild时，可以输入第二个为版本号的参数"
	exit 2
fi

function startserver()
{
	ulimit -c unlimited
	num=$(ps aux | grep "$1" | grep -v 'grep' | wc -l)
	if [ "$num" -lt "1" ]
	then
		echo "start ======================="
		cd `pwd`/bin
		$1 > /tmp/null &
	fi
}

function stopserver()
{
	for i in `ps aux | grep "$1" | grep -v 'grep' | awk '{print $2}'`
	do
		echo "stop ======================="
		kill $i
	done
}

function rebuild()
{
	if [ "${NIREUS_BUILD_THREAD_CNT}" = "" ]
	then
		NIREUS_BUILD_THREAD_CNT=2
	fi
	make -C $PROJECT_NAME clean

	make -C $PROJECT_NAME -j${NIREUS_BUILD_THREAD_CNT} VERSION=$1 PROJECT=$PROJECT_NAME
	if [ $? -ne 0 ]
	then
		echo -e "\033[31m========== ${PROJECT_NAME} build failed ============\033[0m"
		exit 2
	fi

	make -C $PROJECT_NAME install VERSION=$1 PROJECT=$PROJECT_NAME
	if [ $? -ne 0 ]
	then
		echo -e "\033[31m========== ${PROJECT_NAME} install failed ============\033[0m"
		exit 2
	fi
}

function reload()
{
	for i in `ps aux | grep "$1" | grep -v 'grep' | awk '{print $2}'`
	do
		echo "reload ======================="
		kill -USR1 $i
	done
}

function gcore()
{
	for i in `ps aux | grep "$1" | grep -v 'grep' | awk '{print $2}'`
	do
		echo "gcore ======================="
		/usr/bin/gcore $i
	done
}

case "$1" in
	start)
		startserver "$COMMAND_LINE"
		;;
	restart)
		stopserver "$COMMAND_LINE"
		startserver "$COMMAND_LINE"
		;;
	stop)
		stopserver "$COMMAND_LINE"
		;;
	show)
		ps aux | grep "$COMMAND_LINE" | grep -v 'grep'
		;;
	rebuild)
		VERSION=1.0.0
		if [ "$#" -ge "2" ]
		then
			VERSION=$2
		fi
		rebuild $VERSION
		;;
	reload)
		reload "$COMMAND_LINE"
		startserver "$COMMAND_LINE"
		;;
	gcore)
		gcore "$COMMAND_LINE"
		;;
	*)
		echo "parameter must = [start|restart|stop|rebuild|show|reload|gcore]"
		;;
esac

exit 0