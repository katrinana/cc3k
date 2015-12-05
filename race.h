#ifndef __RACE_H_
#define __RACE_H_
 
#include "player.h"

class Race: public Player{
public:
	Race(char** maps);
	virtual ~Race();
};

#endif
