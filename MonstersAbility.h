#ifndef MONSTERS_ABILITY_H
#define MONSTERS_ABILITY_H

#include "Monsters.h"


class Unit;
class Monsters;

class MonstersAbility : public Ability {
protected:
	Monsters* owner;
public:	
	MonstersAbility(AbilityType type, Monsters* owner, int damage);	
	~MonstersAbility();	
    virtual void action(Unit* target) = 0;
	virtual void reaction(Unit* target) = 0;
	virtual Monsters* bite(Unit* target) = 0;
	Monsters* getOwner() const;
};

#endif
