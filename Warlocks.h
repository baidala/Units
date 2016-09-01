#ifndef WARLOCKS_H
#define WARLOCKS_H

#include "Spellcaster.h"


class Warlocks : public Spellcaster {
public:
	Warlocks(UnitType unitType, State* state, Ability* ability);
	~Warlocks();
	
	virtual void cast(Spellname spellname, Unit* target) = 0;
	void attack(Unit* enemy);        
	void counterAttack(Unit* enemy);        
	virtual void destroy() = 0;
};

#endif
