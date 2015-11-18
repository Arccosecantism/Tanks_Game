#pragma once
#include "IncludeMe.h"
class Controls
{
	typedef void(*function_pointer)(void*);
	typedef std::pair<function_pointer, void*> memfunc_of_object;

public:
	Controls();
	~Controls();
	void addKey(int key);
	void addFunctionTokey(memfunc_of_object function, int key);
	void callKeyFuncs(std::vector<int>& fkeys);


private:

	std::map<int, std::vector<memfunc_of_object>> keysAndFunctions;
};

