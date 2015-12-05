#include "halfing.h"
using namespace std;

Halfing::Halfing(): Enemy(100, 15, 20, 'L'){
	//srand(time(0));
	gold = randomgenerate(2);
}

Halfing::~Halfing(){}

string Halfing::getFullname() {
	return "Halfing";
}

int Halfing::getgold() {
	return gold;
}
