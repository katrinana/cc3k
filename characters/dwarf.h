#ifndef __DWARF_H__
#define __DWARF_H__
#include "enemy.h"

class Dwarf: public Enemy{
	int gold;
public:
	Dwarf();
	~Dwarf();
	std::string getFullname();
	int getgold();
};
#endif
