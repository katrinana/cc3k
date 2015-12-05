#ifndef __RH_H__
#define __RH_H__
#include "potion.h"

class RH : public Potion {
public:
	RH();
	~RH();
	bool isPermant();
	void change(Player *p);
};
#endif
