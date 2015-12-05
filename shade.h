#ifndef __SHADE_H_
#define __SHADE_H_

#include "race.h"
#include <iostream>

class Shade: public Race{
public:
	Shade(char** maps);
	std::string getFullname();
	char Getch();
	
    ~Shade();
};

#endif