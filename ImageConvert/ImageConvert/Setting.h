#pragma once

class Setting
{
	SINGLETON_DECLARATION(Setting);

	DEFINE_PROPERTY_REF(String, path);

public:
	Setting();
	~Setting();

	void init();
};