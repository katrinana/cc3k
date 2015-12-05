#ifndef __CEIL_H__
#define __CEIL_H__
#include <string>
#include "object.h"
//#include "player.h"
#include "enemy.h"
#include "potion.h"
#include "treasure.h"
#include "dragon.h"
class Player;
class Object;
class Treasure;
class Potion;
class Enemy;
//class Dragon;
class Cell {
	int numchamber;
	int r, c;
	char state;
	Object *ob;
	//Player *pl;
public:
	Cell(int r = 0, int c = 0, char state = ' ');
	~Cell();
	char getState();
	int getChamber();
	//void setPlayer(Player *p);
	//void removePlayer();
	void renewState(char cc);
	void changeObject(Object *oo);
	Enemy* setEnemy(char name);
	Treasure* setTreasure(std::string tt);
	Treasure* setDragonhoard(Dragon *d);
	void placeDragon(Dragon *d);
	Potion* setPotion(std::string pp);
	Object* getObject();
	//Player* getPlayer();
};
#endif
