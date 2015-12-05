#include "troll.h"
using namespace std;

Troll::Troll(char** maps):Race(maps){
	hp = 120;
	init_atk = 25;
	atk = 25;
	init_atk = 25;
	def = 15;
	//ch = 'T';
};

string Troll::getFullname(){
	return "troll ";
}

char Troll::Getch(){
	return 't';
}

Troll::~Troll(){}