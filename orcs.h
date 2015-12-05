#ifndef __ORCS_H__
#define __ORCS_H__
#include "enemy.h"

class Orcs: public Enemy {
	int gold;
public:
	Orcs();
	~Orcs();
	std::string getFullname();
	int getgold();
};
#endif
