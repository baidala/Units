#ifndef CLOSE_QUARTER_ATTACK_H
#define CLOSE_QUARTER_ATTACK_H

#include "Ability.h"

class CloseQuarterAttack : public Ability {
public:
	CloseQuarterAttack(AbilityType type, Unit* owner, int damage);
	~CloseQuarterAttack();

	void action(Unit* target);
	void reaction(Unit* target);  
};

#endif
