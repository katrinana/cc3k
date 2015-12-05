#include "enemy.h"
#include "object.h"

Enemy::Enemy(double hp, double atk, double def, char name): Object(name), hp(hp), atk(atk), def(def){}

double Enemy::getHP() {
	return hp;
}

double Enemy::getAtk() {
	return atk;
}

double Enemy::getDef() {
	return def;
}

double Enemy::changeHP(int amt) {
	double ddd = damage(def, amt);
	hp = hp - ddd;
	return ddd;
}

bool Enemy::isDeath() {
	if (hp <= 0) {
		return true;
	} else {
		return false;
	}
}

void Enemy::changehostile() {}

Treasure* Enemy::getdhoard() {return NULL;}

bool Enemy::gethostile() {return false;}

Enemy::~Enemy() {}
