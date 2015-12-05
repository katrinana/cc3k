#ifndef __BD_H__
#define __BD_H__
#include "potion.h"

class BD : public Potion {
public:
	BD();
	~BD();
	bool isPermant();
	void change(Player *p);
};
#endif
