#include "PriestPower.h"

PriestPower::PriestPower(AbilityType type, Unit* owner, int damage) 
	: Ability(type, owner, damage) {}
PriestPower::~PriestPower() {}



void PriestPower::action(Unit* target) {
	UnitType unitType = this->getOwner()->getUnitType();
	
	if ( unitType == VAMPIRE || unitType == NECROMANCER ) {
		target->takeDamage(damage*2);
		target->isAlive();
		target->counterAttack(this->getOwner());
	} else {
		target->takeDamage(damage);
		target->isAlive();
		target->counterAttack(this->getOwner());
	}

	
}

void PriestPower::reaction(Unit* target) {
	UnitType unitType = this->getOwner()->getUnitType();
	
	target->isAlive();
	if ( unitType == VAMPIRE || unitType == NECROMANCER ) {
		target->takeDamage(this->getDamage());
	} else {
		target->takeDamage(this->getDamage() / 2);
	}
	
    
}
