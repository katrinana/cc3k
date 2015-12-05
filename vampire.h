#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

#include<iostream>
#include<string>
#include "race.h"

class Vampire:public Race{
public:
	Vampire(char** maps);
	std::string getFullname();
	//char getch();
	char Getch();
	~Vampire();
};

#endif
