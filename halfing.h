#ifndef __HALFING_H__
#define __HALFING_H__
#include "enemy.h"

class Halfing: public Enemy{
	int gold;
public:
	Halfing();
	~Halfing();
	std::string getFullname();
	int getgold();
};
#endif
