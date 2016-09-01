#include "MonstersAbility.h"

MonstersAbility::MonstersAbility(AbilityType type, Monsters* owner, int damage) : Ability (type, owner, damage){}

MonstersAbility::~MonstersAbility() {}

Monsters* MonstersAbility::getOwner() const {
	return this->owner;
}
