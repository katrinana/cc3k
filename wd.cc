#include "wd.h"
#include "player.h"

WD::WD():Potion("WD", -5) {}

WD::~WD() {}

bool WD::isPermant() {
	return false;
}

void WD::change(Player *p) {
	//cout << "phph" << endl;
	if (p->Getch() == 'd') {
		double ttt = effect * 1.5;
		p->changedef(-ttt);
	}else {
		p->changedef(-effect);
	}
}
