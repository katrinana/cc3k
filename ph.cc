#include "ph.h"
#include "player.h"

PH::PH(): Potion("PH", -10){}

PH::~PH() {}

bool PH::isPermant() {return true;}

void PH::change(Player *p) {
	//cout << "phph" << endl;
	if (p->Getch() == 'd') {
		double ttt = effect * 1.5;
		p->changehp(-ttt);
	} else {
		p->changehp(-effect);
	}
}
