#include "bd.h"
#include "player.h"

BD::BD():Potion("BD", 5) {}

BD::~BD() {}

bool BD::isPermant() {
	return false;
}

void BD::change(Player *p) {
	//cout << "phph" << endl;
	if (p->Getch() == 'd') {
		double ttt = effect * 1.5;
		p->changedef(ttt);
	} else {
		p->changedef(effect);
	}
}
