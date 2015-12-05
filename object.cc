#include "object.h" 
#include "player.h"
#include "dragon.h"
using namespace std;

Object::Object(char name): r(0), c(0), name(name) {}
void Object::setCoord(int r, int c) {
	this->r = r;
	this->c = c;
}

void Object::changeCoord(int newr, int newc) {
	r = newr;
	c = newc;
}

int Object::getRow() {return r;}

int Object::getCol() {return c;}

char Object::getname() {return name;}

void Object::setAmount(int amt) {}

void Object::setDragonhoard(Dragon *d) {}

string Object::getFullname() {return "";}

double Object::changeHP(int amt) {return 0;}

bool Object::isDeath() {return false;}

int Object::getgold() {return 0;}

string Object::getType() {return "";}

void Object::change(Player *p) {}

string Object::getSize() {return "";}

void Object::setDragon(Dragon *d) {}

Dragon* Object::getDragon() {return NULL;}

int Object::getEffect() {return 0;}

double Object::getHP() {return 0;}

double Object::getAtk() {return 0;}

double Object::getDef() {return 0;}

Object::~Object() {}
