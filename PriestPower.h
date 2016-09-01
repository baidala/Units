#ifndef PRIEST_POWER_H
#define PRIEST_POWER_H

#include "Ability.h"

class PriestPower : public Ability {
public:
	PriestPower(AbilityType type, Unit* owner, int damage);
	~PriestPower();

	void action(Unit* target);
	void reaction(Unit* target);  
};

#endif
