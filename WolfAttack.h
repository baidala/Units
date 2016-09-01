#ifndef WOLF_ATTACK_H
#define WOLF_ATTACK_H

#include "MonstersAbility.h"

class Monsters;

class WolfAttack : public MonstersAbility {
private:
	WolfAttack(Monsters* owner);
	static WolfAttack* wa_instance;
public:
	~WolfAttack();
    static WolfAttack* getInstance(Monsters* owner);
	void action(Unit* target);
	void reaction(Unit* target);  
	Monsters* bite(Unit* target);
};

#endif
