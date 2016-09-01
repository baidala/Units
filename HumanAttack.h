#ifndef HUMAN_ATTACK_H
#define HUMAN_ATTACK_H

#include "MonstersAbility.h"

class HumanAttack : public MonstersAbility {
private:
	HumanAttack(Monsters* owner);
	static HumanAttack* ha_instance;
public:
    ~HumanAttack();
    static HumanAttack* getInstance(Monsters* owner);
	void action(Unit* target);
	void reaction(Unit* target);
	Monsters* bite(Unit* target);  
};

#endif
