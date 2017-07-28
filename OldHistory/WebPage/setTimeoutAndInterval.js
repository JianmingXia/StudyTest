/**
 * Created by ryoma on 15-12-4.
 */

//① setInterval()会多次执行要定时执行的代码或函数。经过了那个固定的时间间隔，它还会自动重复执行代码。

//② setTimeout()只会执行一次那段代码或者指定的函数。

//1.循环执行
//下面的JS语句实现的是每过十分钟执行一次circulateExecute()方法。
//循环执行，每十分钟一次。10分钟后第一次执行。
setInterval("circulateExecute();", 10 * 60 * 1000);//10分钟执行一次



//2.下一个整点，或者某个时刻定点执行
//以下javascript代码实现的是实现在当前时刻的下一个整点定点执行nextIntegralPointAfterLogin()方法。

var date = new Date();//现在时刻
var dateIntegralPoint = new Date();//用户登录时刻的下一个整点，也可以设置成某一个固定时刻
dateIntegralPoint.setHours(date.getHours()+1);
dateIntegralPoint.setMinutes(0);
dateIntegralPoint.setSeconds(0);
setTimeout("nextIntegralPointAfterLogin();", dateIntegralPoint - date);//用户登录后的下一个整点执行。


//3.每一个整点定点执行
//通过上面介绍的在下一个整点执行nextIntegralPointAfterLogin()函数后，为了实现在每一个整点都执行某函数，可以在nextIntegralPointAfterLogin()函数中写上以下代码。

function nextIntegralPointAfterLogin(){

    IntegralPointExecute();//在整点执行的函数，在每个整点都调用该函数
    setInterval("IntegralPointExecute();",60*60*1000);//一个小时执行一次，那么下一个整点，下下一个整点都会执行

}

//QA
// setHours(date.getHours() + 1)    =>未验证