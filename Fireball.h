#ifndef FIREBALL_H
#define FIREBALL_H


#include "Spell.h"

class Fireball: public Spell {
private:
	UnitType owner;
public:
	Fireball();
	Fireball(int cost, int spellpower);
	~Fireball();

	void action(Unit* target);
};

#endif
