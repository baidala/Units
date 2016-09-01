#include "VampireAttack.h"

VampireAttack::VampireAttack(AbilityType type, Monsters* owner, int damage) 
	: MonstersAbility(type, owner, damage) {}

VampireAttack::~VampireAttack() {}

void VampireAttack::action(Unit* target) {
	target->takeDamage(damage);
	target->isAlive();
	target->counterAttack(this->getOwner());
}

void VampireAttack::reaction(Unit* target) {
	target->isAlive();
    target->takeDamage(this->getDamage() / 2);
    this->getOwner()->addHitPoints(damage/2);
}

Monsters* VampireAttack::bite(Unit* target) {
	UnitType unitType = target->getUnitType();
	
	target->takeDamage(target->getState()->hitPointsLimit);
	this->getOwner()->addHitPoints(damage);
	
	if (unitType == VAMPIRE || unitType == WEREWOLF) {
		return NULL;
	}
	target->destroy();
	return this->getOwner()->clone();
	
}
