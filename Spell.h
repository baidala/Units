#ifndef SPELL_H
#define SPELL_H


#include "Unit.h"
//class Unit;

class Spell {
protected:
	int cost;
	int spellpower;

public:
	Spell(int cost, int spellpower);
	~Spell();

	const int getCost() const;
	const int getSpellpower() const;
	
	virtual void action(Unit* target) = 0;
};

#endif
