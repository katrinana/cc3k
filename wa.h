#ifndef __WA_H__
#define __WA_H__
#include "potion.h"

class WA : public Potion {
public:
	WA();
	~WA();
	bool isPermant();
	void change(Player *p);
};
#endif
