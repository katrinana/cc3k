#include "drow.h"

using namespace std;

Drow::Drow(char** maps): Race(maps){
	hp = 150;
	init_atk=25;
	atk=25;
	init_def=15;
	def=15;
}

string Drow::getFullname(){
	return "drow ";
}

char Drow::Getch(){
	return 'd';
}
Drow::~Drow(){};