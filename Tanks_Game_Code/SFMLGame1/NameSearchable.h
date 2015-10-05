#pragma once
#include "SFMLbase.h"

class NameSearchable
{
public:
	NameSearchable();
	~NameSearchable();

protected:
	
	std::string intToString(int finput);

	int ntoi(std::string fname);

	int ntoi(std::string fname, int findex);

	

	void setVectorSize(int fsize);


	void addName(int fintname, int fend);

	void addName(int fintname, int findex, int fend);

	void addName(std::string fname, int fend);

	void addName(std::string fname, int findex, int fend);
	

	std::vector<std::map<std::string, int> > nameMapVector;
};

