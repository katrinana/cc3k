#include "ba.h"
#include "player.h"
#include "potion.h"
using namespace std;

//class Player;
BA::BA():Potion("BA", 5) {}

BA::~BA() {}

bool BA::isPermant() {
	return false;
}

void BA::change(Player *p) {
	//cout << "phph" << endl;
	if (p->Getch() == 'd') {
		double ttt = effect * 1.5;
		p->changeatk(ttt);
	}else {
		p->changeatk(effect);
	}
}
