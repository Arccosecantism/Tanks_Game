#include "NameSearchable.h"
#include <sstream>


NameSearchable::NameSearchable()
{
}


NameSearchable::~NameSearchable()
{
}




std::string NameSearchable::intToString(int finput)
{
	std::stringstream ss;
	ss << finput;
	return ss.str();
}


int NameSearchable::ntoi(std::string fname)
{
	return ntoi(fname, 0);
}


int NameSearchable::ntoi(std::string fname, int findex)
{
	int tmp = nameMapVector[findex][fname];
	return tmp;
}




void NameSearchable::setVectorSize(int fsize)
{
	std::map<std::string, int> tmpMap;
	for (int i = 0; i < fsize; i ++)
	{
		nameMapVector.push_back(tmpMap);
	}
}


void  NameSearchable::addName(int fintname, int fend)
{
	addName(fintname, 0, fend);
}

void  NameSearchable::addName(int fintname, int findex, int fend)
{
	std::string tmpString = "Unnamed" + intToString(fintname) + ".";
	addName(tmpString, findex, fend);
}

void NameSearchable::addName(std::string fname, int fend)
{
	addName(fname, 0, fend);
}

void NameSearchable::addName(std::string fname, int findex, int fend)
{
	bool sameName = true;
	bool firstDuplicate = true;

	while (sameName == true)
	{

		if (nameMapVector[findex].count(fname) == 1)
		{
			if (firstDuplicate == true)
			{
				fname += "2";							/*if there exists a "RedTexture" already, and you try to add another one,
														it will become "RedTexture2"*/

				firstDuplicate = false;
			}
			else
			{
				fname[fname.size() - 1]++;				/*if there exists a "RedTexture2" already, and you try to add another one,
														it will become "RedTexture3"*/

			}
		}

		else
		{
			sameName = false;							//if therer is no same name, exit the while loop
		}

	}

	nameMapVector[findex][fname] = fend;						//then add the altered (or not) name
}