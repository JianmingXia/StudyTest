#pragma once

class OutputManager
{
	SINGLETON_DECLARATION(OutputManager);

public:
	OutputManager(void);
	virtual ~OutputManager(void);

	void output11_21();
};