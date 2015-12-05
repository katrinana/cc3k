#ifndef __HUMAN_H__
#define __HUMAN_H__
#include "enemy.h"
#include <string>

class Human: public Enemy{
	int gold;
public:
	Human();
	~Human();
	std::string getFullname();
	int getgold();
};

#endif