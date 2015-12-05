#ifndef __ELF_H__
#define __ELF_H__
#include "enemy.h"

class Elf: public Enemy {
	int gold;
public:
	Elf();
	~Elf();
	std::string getFullname();
	int getgold();
};

#endif
