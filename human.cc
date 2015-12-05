#include "human.h"
#include <string>
using namespace std;

Human::Human(): Enemy(140, 20, 20, 'H'), gold(2){}

Human::~Human() {}

string Human::getFullname() {
	return "Human";
}

int Human::getgold() {
	return gold;
}
