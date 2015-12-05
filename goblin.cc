#include "goblin.h"
using namespace std;

Goblin::Goblin(char** maps): Race(maps){
	hp=110; 
	init_atk=15;
	atk=15;
	init_def=20; 
	def=20;
};

string Goblin::getFullname(){
	return "goblin ";
}

char Goblin::Getch(){
	return 'g';
}


Goblin::~Goblin(){};