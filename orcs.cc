#include "orcs.h"
using namespace std;

Orcs::Orcs(): Enemy(180, 30, 25, 'O') {
	//srand(time(0));
	gold = randomgenerate(2);
}

string Orcs::getFullname() {
	return "Orcs";
}

Orcs::~Orcs() {}

int Orcs::getgold() {
	return gold;
}
