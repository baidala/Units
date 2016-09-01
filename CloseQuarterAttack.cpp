#include "CloseQuarterAttack.h"

CloseQuarterAttack::CloseQuarterAttack(AbilityType type, Unit* owner, int damage) 
	: Ability(type, owner, damage) {}
CloseQuarterAttack::~CloseQuarterAttack() {}

void CloseQuarterAttack::action(Unit* target) {
	target->takeDamage(damage);
	target->isAlive();
	target->counterAttack(this->getOwner());
}

void CloseQuarterAttack::reaction(Unit* target) {
	target->isAlive();
    target->takeDamage(this->getDamage() / 2);
}
