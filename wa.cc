#include "wa.h"
#include "player.h"

WA::WA():Potion("WA", -5) {}

WA::~WA() {}

bool WA::isPermant() {
	return false;
}

void WA::change(Player *p) {
	//cout << "phph" << endl;
	if (p->Getch() == 'd') {
		double ttt = effect * 1.5;
		p->changeatk(-ttt);
	} else {
		p->changeatk(-effect);
	}
}
