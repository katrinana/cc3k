#ifndef __ENEMY_H__
#define __ENEMY_H__
#include <cstdlib>
#include <ctime>
#include "object.h"
#include "random.h"

//class Object;
class Treasure;
class Enemy: public Object {
protected:
	double hp;
	double atk;
	double def;
public:
	Enemy(double hp, double atk, double def, char name);
	virtual ~Enemy();
	virtual std::string getFullname() = 0;
	virtual int getgold() = 0;
	virtual void changehostile();
	virtual bool gethostile();
	virtual Treasure* getdhoard();
	double getHP();
	double getAtk();
	double getDef();
	double changeHP(int amt);
	bool isDeath();
};

#endif
