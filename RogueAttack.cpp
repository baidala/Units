#include "RogueAttack.h"

RogueAttack::RogueAttack(AbilityType type, Unit* owner, int damage) 
	: Ability(type, owner, damage) {}
	
RogueAttack::~RogueAttack() {}

void RogueAttack::action(Unit* target) {
	target->takeDamage(damage);
}

void RogueAttack::reaction(Unit* target) {
	target->isAlive();
    target->takeDamage(this->getDamage() / 2);
}
