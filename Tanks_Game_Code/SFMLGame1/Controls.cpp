//#include "Controls.h"
//
//
//Controls::Controls()
//{
//}
//
//
//Controls::~Controls()
//{
//}
//
//void Controls::addKey(int key)
//{
//	bool newKey = true;
//	if (keysAndFunctions.count(key))
//	{
//		newKey = false;
//	}
//
//	if (newKey)
//	{
//		std::vector<memfunc_of_object> tmp;
//		keysAndFunctions[key] = tmp;
//	}
//
//}
//
//void Controls::addFunctionToKey(memfunc_of_object function, int key)
//{
//	keysAndFunctions[key].push_back(function);
//}
//
//void Controls::callKeyFuncs(std::vector<int>& fkeys)
//{
//	for (int i = 0; i < fkeys.size(); i++)
//	{
//		for (int j = 0; j < keysAndFunctions[i].size(); j++)
//		{
//			keysAndFunctions[i][j].first(keysAndFunctions[i][j].second);
//		}
//	}
//}