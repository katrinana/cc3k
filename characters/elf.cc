#include "elf.h"
using namespace std;

Elf::Elf(): Enemy(140, 30, 10, 'E'){
	//srand(time(0));
	gold = randomgenerate(2);
}

Elf::~Elf(){}

string Elf::getFullname() {
	return "Elf";
}

int Elf::getgold() {
	return gold;
}
