#ifndef __DROW_H__
#define __DROW_H__

#include <iostream>
#include <string>
#include "race.h"


class Drow:public Race{
public:
	Drow(char** maps);
	std::string getFullname();
	char Getch();
	~Drow();
};

#endif

