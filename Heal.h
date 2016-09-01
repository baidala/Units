#ifndef HEAL_H
#define HEAL_H

#include "Spell.h"


class Heal: public Spell {
private:
	UnitType owner;
public:
	Heal();
	Heal(int cost, int spellpower);
	~Heal();

	void action(Unit* target);
};

#endif
