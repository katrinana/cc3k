#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
#include "potion.h"
#include "floor.h"
#include "treasure.h"
#include "enemy.h"
#include "cell.h"
//#include "object.h"

class Potion;
//class Object;
class Floor;
class Potion;
class Treasure;
class Dragon;
class Enemy;
class Cell;
class Player {
protected:
	int row;
	int col;
	int gold;
	int currentfloor;
	double hp;
	double init_atk;
	double atk;
	double init_def;
	double def;
	//char col, row;
	//char ch;
    Floor *f[5];
	char **map;
	bool dead;
	bool won;
	
public:
	Player(char** maps);
	virtual ~Player();
	std::string move(std::string m);
	virtual std::string getFullname() = 0;
	//virtual char getch() = 0;
	virtual char Getch() = 0;
	bool islose();
	bool iswon();
	std::string combat(Object *en);
	int getgold();
	double getHP();
	double getDef();
	double getAtk();
	void changecoord(int a, int b);
    void setcoord(int m, int n); 
	void changegold(int g);
	void changehp(double c);
	void changeatk(double c);
	void changedef(double c);
	
	void printscore();
	
	void Display(std::string act="");
	std::string Enemymove();
};

#endif
