#include "dragon.h"
#include "object.h"
#include <stdlib.h>
using namespace std;

Dragon::Dragon() : Enemy(150, 20, 20, 'R'), dhoard(NULL){}

Dragon::~Dragon() {}

int Dragon::getgold() {return 0;}

string Dragon::getFullname() {
	return "Dragon";
}

void Dragon::setdhoard(Treasure *hoard) {
	dhoard = hoard;
	//hoard->setDragon(this);
}

Treasure * Dragon::getdhoard() {
	return dhoard;
}
