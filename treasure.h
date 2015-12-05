#ifndef __TREASURE_H__
#define __TREASURE_H__
#include <iostream>
#include <string>
#include "object.h"
//#include "enemy.h"
#include "dragon.h"

//class Enemy;
class Dragon;
//class Object;
class Treasure : public Object {
protected:
	int amount;
	std::string size;
	Dragon *dragon;
public:
	Treasure();
	~Treasure();
	int getEffect();
	std::string getSize();
	void setAmount(int amt);
	void setDragon(Dragon *d);
	Dragon* getDragon();
};

#endif
