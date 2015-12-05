#ifndef __WD_H__
#define __WD_H__
#include "potion.h"

class WD : public Potion {
public:
	WD();
	~WD();
	bool isPermant();
	void change(Player *p);
};
#endif
