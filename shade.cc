#include "shade.h"
using namespace std;

Shade::Shade(char** maps): Race(maps){
	hp=125;
    init_atk=25;
	atk=25;
	init_def=25; 
	def=25;
}

string Shade::getFullname(){
	return "shade";
}

char Shade::Getch(){
	return 's';
}


Shade::~Shade(){}