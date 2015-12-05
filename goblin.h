#ifndef __GOBLIN_H__
#define __GOBLIN_H__

#include<iostream>
#include<string>
#include "race.h"

class Goblin:public Race{
public:
	Goblin(char** maps);
	std::string getFullname();
	char Getch();

	~Goblin();
};

#endif
