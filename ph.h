#ifndef __PH_H__
#define __PH_H__
#include "potion.h"

class PH : public Potion {
public:
	PH();
	~PH();
	bool isPermant();
	void change(Player *p);
};
#endif
