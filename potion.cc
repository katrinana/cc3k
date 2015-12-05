#include "potion.h"
//#include "object.h"
//#include "player.h"
using namespace std;

Potion::Potion(string type, int effect): Object('P'), type(type), effect(effect){}

void Potion::change(Player *p){}

string Potion::getType() {
	return type;
}

int Potion::getEffect() {
	return effect;
}
