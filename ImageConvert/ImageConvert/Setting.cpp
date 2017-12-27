#include "PreCompiled.h"
#include "Setting.h"

SINGLETON_DEFINITION(Setting);
Setting::Setting()
{
}

Setting::~Setting()
{

}

void Setting::init()
{
	_path = CommandParser::getInstance().getString("path", "../");
}