#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include "enemy.h"

class Merchant: public Enemy {
	int gold;
	bool isattack;
public:
	Merchant();
	~Merchant();
	std::string getFullname();
	bool gethostile();
	void changehostile();
	int getgold();
};
#endif
