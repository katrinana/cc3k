#ifndef __POTION_H__
#define __POTION_H__
#include "object.h"
//#include "player.h"
#include <string>

//class Object;
class Player;
class Potion: public Object {
protected:
	std::string type;
	int effect;
public:
	Potion(std::string type,int effect);
	int getEffect();
	virtual void change(Player *p);
	virtual bool isPermant() = 0;
	std::string getType();
};

#endif
