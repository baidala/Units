#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Monsters.h"
#include "WolfAttack.h"
#include "HumanAttack.h"
#include "WolfState.h"
#include "HumanState.h"


class Observer;
class Unit;

class Werewolf : public Monsters {
public:
	Werewolf();
	~Werewolf();
	void changeState();
	void takeMagicDamage(int damage);
	Monsters* biteWound(Unit* enemy);
    Werewolf* clone() const;
    void destroy();
};

#endif
