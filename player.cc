#include "player.h"
#include "floor.h"
#include "random.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "potion.h"
#include "wa.h"
#include "wd.h"
#include "ba.h"
#include "bd.h"
#include "ph.h"
#include "rh.h"
#include <sstream>
#include <unistd.h>
#include<ncurses.h>
#include<stdlib.h> 

using namespace std;

Player::Player(char** maps):row(0), col(0), gold(0), currentfloor(0), map(maps), dead(false), won(false){
	f[0] = new Floor(this, 0, map);
	for(int i = 1; i < 4; i++){
		f[i] = NULL;
	}
}

Player::~Player() {
	for (int i = 0; i < 5; i++) {
		if (f[i] != NULL){
			delete f[i];
		}
	}
	if (map != NULL) {
		for (int i = 0; i < 25; i++) {
			delete[] map[i];
		}
		delete [] map;
	}
}

double Player::getHP() {
	return hp;
}

double Player::getDef() {
	return def;
}

double Player::getAtk() {
	return atk;
}

int Player::getgold(){
	return gold;
}

void Player::changecoord(int a, int b){
	row = row + a;
	col = row + b;
}

void Player::setcoord(int m, int n){
	row = m;
	col = n;
}

void Player::changegold(int g){
	gold = gold + g;
}
void Player::changehp(double c){
	hp = hp - c;
}

void Player::changeatk(double c){
	atk = atk + c;
}

void Player::changedef(double c){
	def = def + c;
}

bool Player::islose(){
	if (hp <= 0){
		dead = true;
	}
	return dead;
}

bool Player::iswon() {
	return won;
}

string Player::combat(Object *en) {
	//srand(time(0));
	string action = "";
	string naa = en->getFullname();
	//cout << naa << endl;
	char na = en->getname();
	int dama = 0;
	if (Getch() == 'v') {
		changehp(5);
		if (na == 'D') {
			changehp(-10);
		}
	}
	if (Getch() == 't') {
		changehp(5);
		if (hp >= 120) {
			hp = 120;
		}
	}
	/*if (getch() == 'g') {
		changegold(5);
	}*/
	if (na == 'L') {
		int miss = randomgenerate(2) - 1;
		dama = en->changeHP(atk * miss);
		if (miss == 0) {
			action = "You missed because of Halfing.";
		} else {
			action = "You deals " + damage_string(dama) + " damage to halfing.";
		}
	}else {
		dama = en->changeHP(atk);
		action = "You deals " + damage_string(dama) + " damage to " + naa + ".";
	}
	return action;
}

string convert(int i) {
	string result;
	if (i == 1) {
		result = "second";
	} if (i == 2) {
		result = "third";
	} if ( i == 3) {
		result = "forth";
	} if (i == 4) {
		result = "fifth";
	}
	return result;
}

string Player::move(string m) {
	int prevr = row;
	int prevc = col;
	string dir;
	string info = "You pick up a ";
	string action = "";
	string slay = "You slay a ";
	string enemymo = "";
	if (m == "no") {
		row--;
		dir = "North";
	} else if (m == "so"){
		row++;
		dir = "South";
	} else if (m == "ea"){
		col++;
		dir = "East";		
	} else if (m == "we"){
		col--;
		dir = "West";
	} else if (m == "ne"){
		col++;
		row--;
		dir = "NorthEast";
	} else if (m == "nw"){
		col--;
		row--;
		dir = "NorthWest";
	} else if (m == "se"){
		col++;
		row++;
		dir = "SouthEast"; 		
	} else if (m == "sw"){
		col--;
		row++;
		dir = "SouthWest";
	}else{
		action = "cannot read the direction, please choose from (no/so/ea/we/ne/nw/se/sw).\n";
		return action;
	}

	char nextstate = f[currentfloor]->getCell(row, col).getState();
	if (nextstate == '.' || nextstate == '+' || nextstate == '#') {
		//cout << " check " << endl;
		f[currentfloor]->notify(prevr, prevc, row, col);
		action = "You move to " + dir + ". ";
	} else if (nextstate == 'G') {
		Treasure *t1;
		for (int i = 0; i < 10; i++) {
			t1 = f[currentfloor]->getTreasure(i);
			if (t1->getRow() == row && t1->getCol() == col) {
				break;
			}
		}
		
		if (t1->getDragon() == NULL) {
			changegold(t1->getEffect());
			f[currentfloor]->notify(prevr, prevc, row, col);
			f[currentfloor]->getCell(row, col).changeObject(NULL);
			action = info + t1->getSize() + " gold. ";
		} else {
			action = "You need to fight with dragon ro obtain this hoard.\n";
			row = prevr;
			col = prevc;
			
		}
	} else if (nextstate == 'P') {
		Potion *p1;
		for (int i = 0; i < 10; i++) {
			p1 = f[currentfloor]->getPotion(i);
			if (p1->getRow() == row && p1->getCol() == col) {
				break;
			}
		}
		cout << p1->getType() << endl;
		if(p1->getType() == "RH" || p1->getType() == "PH") {
			changehp(p1->getEffect());
		} else if (p1->getType() == "BD" || p1->getType() == "WD") {
			changedef(p1->getEffect());
		} else {
			changeatk(p1->getEffect());
		}
		cout << "1" << endl;
		f[currentfloor]->getCell(row, col).changeObject(NULL);
		//p1->change(this);
		f[currentfloor]->notify(prevr, prevc, row, col);
		//f[currentfloor]->getCell(prevr, prevc).removePlayer();
		//f[currentfloor]->getCell(row, col).setPlayer(this);
		
		action = "You pick up a " + p1->getType() + " potion. ";
		//return action;
	} else if (nextstate == 'H' || nextstate == 'D'|| nextstate == 'L'|| nextstate == 'E'|| nextstate == 'O') {
		Enemy* en1;
		for (int i = 0; i < 20; i++) {
			en1 = f[currentfloor]->getEnemy(i);
			if (en1->getRow() == row && en1->getCol() == col) {
				break;
			}
		}
		string aaa = combat(en1);
		if (en1->isDeath()) {
			action = slay + en1->getFullname() + ". " + action;
			f[currentfloor]->getCell(row, col).renewState('.');
			int numgold = en1->getgold();
			changegold(numgold);
			if (Getch() == 'g') {
				changegold(5);
			}
			f[currentfloor]->getCell(row, col).changeObject(NULL);
		}
		action = aaa + " " + action + " ";
		row = prevr;
		col = prevc;
		//return action;
	} else if (nextstate == 'M') {
		Enemy *en1;
		for (int i = 0; i < 20; i++) {
			en1 = f[currentfloor]->getEnemy(i);
			if (en1->getRow() == row && en1->getCol() == col) {
				break;
			}
		}
		string aaa = combat(en1);
		if (en1->isDeath()) {
			action = slay + en1->getFullname() + ". " + action;
			f[currentfloor]->getCell(row, col).renewState('.');
			
			int numgold = en1->getgold();
			changegold(numgold);
			if (Getch() == 'g') {
				changegold(5);
			}
			f[currentfloor]->getCell(row, col).changeObject(NULL);
		}
		action = aaa + " " + action + " ";
		f[currentfloor]->hostile();  //function that changes the Merchant's isattack;
		//return action;
		row = prevr;
		col = prevc;
	} else if (nextstate == 'R') {
		Enemy* gg;
		for (int i = 0; i < 10; i++) {
			//cout << "1" << endl;
			if(f[currentfloor]->getDDragon(i) != NULL) {
				gg = f[currentfloor]->getDDragon(i);
				//cout << "row " << gg->getRow() <<endl;
				if (gg->getRow() == row && gg->getCol() == col) {
					break;
				}
			}
		}
		//cout << "dragon" << endl;
		string aaa = combat(gg);
		if (gg->isDeath()) {
			action = slay + gg->getFullname() + ". " + action;
			gg->getdhoard()->setDragon(NULL);
			f[currentfloor]->getCell(row, col).renewState('.');
			
			f[currentfloor]->getCell(row, col).changeObject(NULL);
			if (Getch() == 'g') {
				changegold(5);
			}
			
		}
		action = aaa + " " + action + " ";
		row = prevr;
		col = prevc;
	} else if (nextstate == '\\') {
		if (currentfloor <= 3) {
			currentfloor += 1;
			if (f[currentfloor] == NULL) {
				
				f[currentfloor] = new Floor(this, currentfloor, map);
				
			}
			atk = init_atk;
			def = init_def;
			action = "You reach the " + convert(currentfloor) + "floor. "; 
		} else {
			won = true;
			action = "";
		}
	} else {
		row = prevr;
		col = prevc;
		action = "You cannot move to " + dir + ". ";
	}
	enemymo = Enemymove();
	action = action + enemymo + "\n";
	return action;
}

void Player::printscore(){
	printw("Score: %d\n", gold);
}

void Player::Display(string act){
	return f[currentfloor]->printmap(act);
	
}

string Player::Enemymove(){
	return f[currentfloor]->enemymove();
}





