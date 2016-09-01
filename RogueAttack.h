#ifndef ROGUE_ATTACK_H
#define ROGUE_ATTACK_H

#include "Ability.h"

class RogueAttack : public Ability {
public:
	RogueAttack(AbilityType type, Unit* owner, int damage);
	~RogueAttack();

	void action(Unit* target);
	void reaction(Unit* target); 
};

#endif
