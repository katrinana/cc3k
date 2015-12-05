#include "dwarf.h"
using namespace std;
Dwarf::Dwarf(): Enemy(100, 20, 30, 'D'){
	//srand(time(0));
	gold = randomgenerate(2);
}

Dwarf::~Dwarf(){}

string Dwarf::getFullname() {
	return "Dwarf";
}

int Dwarf::getgold() {
	return gold;
}
