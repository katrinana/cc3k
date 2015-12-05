#include "rh.h"
#include "player.h"

RH::RH(): Potion("RH", 10){}

RH::~RH() {}

bool RH::isPermant() {return true;}

void RH::change(Player *p) {
	//cout << "phph" << endl;
	if (p->Getch() == 'd') {
		double ttt = effect * 1.5;
		p->changehp(ttt);
	} else {
		p->changehp(effect);
	}
}
