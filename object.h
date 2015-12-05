#ifndef __OBJECT_H__
#define __OBJECT_H__
#include "random.h"
//#include "player.h"
//#include "treasure.h"
//#include "potion.h"
//#include "enemy.h"
//#include "dragon.h"

class Player;
class Dragon;
class Enemy;
class Potion;
class Treasure;
class Object{
protected:
	int r, c;
	char name;
public:
	virtual ~Object();
	Object(char name);
	virtual void setAmount(int amt);
	virtual void setDragonhoard(Dragon *d);
	virtual std::string getFullname();
	virtual double changeHP(int amt);
	virtual bool isDeath();
	virtual int getgold();
	virtual std::string getType();
	virtual void change(Player *p);
	virtual std::string getSize();
	virtual void setDragon(Dragon *d);
	virtual Dragon* getDragon();
	virtual int getEffect();
	void changeCoord(int newr, int newc);
	virtual double getHP();
	virtual double getAtk();
	virtual double getDef();
	void setCoord(int r, int c);
	int getRow();
	int getCol();
	char getname();
};
#endif
