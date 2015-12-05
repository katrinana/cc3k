#include "vampire.h"
using namespace std;

Vampire::Vampire(char** maps):Race(maps){
	hp = 120;
	init_atk = 25;
	atk = 25;
	init_atk = 15;
	def = 15;
	//ch = 'V';
};


string Vampire::getFullname(){
	return "vampire ";
}

/*char Vampire::getch(){
	return 'v';
}*/

char Vampire::Getch(){
	return 'v';
}

Vampire::~Vampire(){}
