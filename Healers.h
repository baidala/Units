#ifndef HEALERS_H
#define HEALERS_H

#include "Spellcaster.h"

class Healers : public Spellcaster {
public:
	Healers(UnitType unitType, State* state, Ability* ability);
	~Healers();
	
	virtual void cast(Spellname spellname, Unit* target) = 0;
	void attack(Unit* enemy);        
	void counterAttack(Unit* enemy);
	virtual void destroy() = 0;        
};

#endif
