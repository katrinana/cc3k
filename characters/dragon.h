#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "enemy.h"
//#include "treasure.h"

class Treasure;
class Dragon: public Enemy {
	Treasure *dhoard;
public:
	Dragon();
	~Dragon();
	std::string getFullname();
	int getgold();
	void setdhoard(Treasure *t);
	Treasure* getdhoard();
};
#endif
