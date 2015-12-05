#ifndef __TROLL_H__
#define __TROLL_H__
#include <iostream>
#include <string>
#include "race.h"

class Troll:public Race{
public:
	Troll(char** maps);
	std::string getFullname();
	char Getch();
	
	~Troll();
};

#endif
