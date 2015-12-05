#include "cell.h"
#include <string>
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfing.h"
#include "ba.h"
#include "bd.h"
#include "wa.h"
#include "wd.h"
#include "ph.h"
#include "rh.h"
#include "player.h"
#include <string>
using namespace std;

Cell::Cell(int r, int c, char state): numchamber(0), r(r), c(c), state(state), ob(NULL) {}

int Cell::getChamber() {
	if ((c > 2) && (c < 29) && (r > 2) && (r < 7)) {
		numchamber = 1;
	} else if ((c > 37) && (c < 50) && (r > 9) && (r < 13)) {
		numchamber = 3;
	} else if ((c > 38) && (c < 76) && ( r > 2) && (r < 13) && (state != ' ') && (state != '#')) {
		numchamber = 2;
	} else if ((c > 3) && (c < 25) && (r > 14) && (r < 22)) {
		numchamber = 4;
	} else if ((c > 36) && (c < 76) && (r > 15) && (r < 22) && (state != ' ') && (state != '#')) {
		numchamber = 5;
	} else {}
	return numchamber;
}

void Cell::renewState(char cc) {
	state = cc;
}

char Cell::getState(){
	return state;
}

/*void Cell::setPlayer(Player *p) {
	pl = p;
	//state = '@';
}

void Cell::removePlayer() {
	pl = NULL;
}*/

void Cell::changeObject(Object *oo) {
	ob = oo;
}

Enemy* Cell::setEnemy(char s) {
	Enemy* eee = NULL;
	if (s == 'H') {
		state = 'H';
		eee = new Human();
		eee->setCoord(r, c);
	} if (s == 'D') {
		state = 'D';
		eee = new Dwarf();
		eee->setCoord(r, c);
	} if (s == 'L') {
		state = 'L';
		eee = new Halfing();
		eee->setCoord(r, c);
	} if (s == 'E') {
		state = 'E';
		eee = new Elf();
		eee->setCoord(r, c);
	} if (s == 'O') {
		state = 'O';
		eee = new Orcs();
		eee->setCoord(r, c);
	} if (s == 'M') {
		state = 'M';
		eee = new Merchant();
		eee->setCoord(r, c);
	}
	ob = eee;
	return eee;
}

Treasure* Cell::setTreasure(string tt) {
	state = 'G';
	Treasure *tr = new Treasure();
	if (tt == "normal") {
		tr->setAmount(2);
		tr->setCoord(r, c);
	} if (tt == "small") {
		tr->setAmount(1);
		tr->setCoord(r, c);
	}
	ob = tr;
	return tr;
}

Treasure* Cell::setDragonhoard(Dragon *d) {
	state = 'G';
	Treasure * tr = new Treasure();
	tr->setAmount(6);
	tr->setCoord(r, c);
	tr->setDragon(d);
	d->setdhoard(tr);
	ob = tr;
	return tr;
}

void Cell::placeDragon(Dragon *d) {
	state = 'R';
	d->setCoord(r, c);
	ob = d;
}

Potion* Cell::setPotion(string pp) {
	state = 'P';
	Potion *po;
	if (pp == "RH") {
		po = new RH();
		po->setCoord(r, c);
	} if (pp == "PH") {
		po = new PH();
		po->setCoord(r, c);
	} if (pp == "BA") {
		po = new BA();
		po->setCoord(r, c);
	} if (pp == "BD") {
		po = new BD();
		po->setCoord(r, c);
	} if (pp == "WA") {
		po = new WA();
		po->setCoord(r, c);
	} if (pp == "WD") {
		po = new WD();
		po->setCoord(r, c);
	}
	ob = po;
	return po;
}

Object* Cell::getObject() {
	return ob;
}

/*Player* Cell::getPlayer(){
	return pl;
}*/

Cell::~Cell() {
	if (ob != NULL){
		delete ob;
	} 
}