#include "treasure.h"
#include "dragon.h"

//#include "object.h"
using namespace std;

Treasure::Treasure(): Object('G'), amount(0), size(""), dragon(NULL){}

string Treasure::getSize() {
	return size;
}

int Treasure::getEffect() {
	return amount;
}

void Treasure::setAmount(int amt) {
	amount = amt;
	if (amt == 1) {
		size = "small";
	} if (amt == 2) {
		size = "normal";
	} if (amt == 4) {
		size = "merchant hoard";
	} if (amt == 6) {
		size = "dragon hoard";
	}
}


void Treasure::setDragon(Dragon *d) {
	dragon = d;
}

Dragon * Treasure::getDragon() {
	return dragon;
}

Treasure::~Treasure() {
	if (dragon != NULL) {
		delete dragon;
	}
}