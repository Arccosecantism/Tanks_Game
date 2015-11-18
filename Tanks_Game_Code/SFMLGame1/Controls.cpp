#include "Controls.h"


Controls::Controls()
{
}


Controls::~Controls()
{
}

void Controls::addKey(int key)
{
	bool newKey = true;
	for (int i = 0; i < keysAndFunctions.size(); i++)
	{
		if (keysAndFunctions[i].first == key)
		{
			newKey = false;
			break;
		}
	}

	if (newKey)
	{
		std::vector<memfunc_of_object> tmp;
		keysAndFunctions.push_back(std::make_pair(key, tmp));
	}

}

void Controls::addFunctionTokey(memfunc_of_object function, int key)
{
	for (int i = 0; i < keysAndFunctions.size(); i++)
	{
		if (keysAndFunctions[i].first == key)
		{
			keysAndFunctions[i].second.push_back(function);
		}
	}
}

void Controls::callKeyFuncs(std::vector<int>& fkeys)
{
	for (int i = 0; i < fkeys.size(); i++)
	{
		for (unsigned int k = 0; k < keysAndFunctions.size(); k++)
		{
			if (keysAndFunctions[k].first == fkeys[i])
			{
				for (unsigned int j = 0)
			}
		}
	}
}