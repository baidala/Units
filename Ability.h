#ifndef ABILITY_H
#define ABILITY_H

#include "Unit.h"

enum AbilityType {
	SWORD,
	AXE,
	DAGGER,
	STICK,
	FANGS
};

class Unit;

class Ability {
protected:	
	int damage;	
	AbilityType type;	
	Unit* owner;	
public:	
	Ability(AbilityType type, Unit* owner, int damage);	
	~Ability();	
	const int getDamage() const;	
	const AbilityType getType() const;
	Unit* getOwner() const;
	virtual void action(Unit* target) = 0;
	virtual void reaction(Unit* target) = 0;		
};

#endif
