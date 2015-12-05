#ifndef __BA_H__
#define __BA_H__
#include "potion.h"

class BA : public Potion {
public:
	BA();
	~BA();
	bool isPermant();
	void change(Player *p);
};
#endif
