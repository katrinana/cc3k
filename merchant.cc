#include "merchant.h"
using namespace std;

Merchant::Merchant() : Enemy(30, 70, 5, 'M'), gold(4), isattack(false){}

Merchant::~Merchant(){}

string Merchant::getFullname() {
	return "Merchant";
}

bool Merchant::gethostile() {
	return isattack;
}

void Merchant::changehostile(){isattack = true;}

int Merchant::getgold() {
	return gold;
}
