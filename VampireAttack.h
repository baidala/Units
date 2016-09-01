#ifndef VAMPIRE_ATTACK_H
#define VAMPIRE_ATTACK_H

#include "MonstersAbility.h"

class Vampire;

class VampireAttack : public MonstersAbility {
public:
	VampireAttack(AbilityType type, Monsters* owner, int damage);
	~VampireAttack();

	void action(Unit* target);
	void reaction(Unit* target);
	Monsters* bite(Unit* target);  
};

#endif
