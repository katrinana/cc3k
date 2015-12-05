#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <string>
#include <iostream>
#include "cell.h"
//#include "player.h"
#include "object.h"
//#include "enemy.h"
//#include "potion.h"
//#include "treasure.h"

class Dragon;
class Player;
class Cell;
class Object;
//class Potion;
//class Treasure;
class Floor{
	int maxenemy;
	int maxpotion;
	int maxtreasure;
	int maxheight;
    int maxwidth;
	
	int playerchamber;
	int level;
	int numenemy;
	int numpotion;
	int numtreasure;
	int numdragon;
			
	Player *play;
	Cell **cells;
	Enemy *enemy[20];
	Treasure *treasure[10];
	Potion *potion[10];
	Dragon *dragon[10];
	
public:
	Floor(Player *p, int l, char** maps);	
	void hostile();
	Cell& getCell(int r, int c);
	void notify(int prec, int prev, int r, int c);
    std::string enemymove();
	Treasure* getTreasure(int numt);
	Dragon* getDDragon(int numd);
	Enemy* getEnemy(int nume);
	Potion* getPotion(int nump);
	void generateenemy();
	void generatepotion();
	void generatetreasure();
	
	void printmap(std::string a);
	~Floor();
};

#endif
