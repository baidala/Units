#include "Ability.h"

Ability::Ability(AbilityType type, Unit* owner, int damage) {
	this->type = type;
	this->owner = owner;
	this->damage = damage;
}
Ability::~Ability() {}

const int Ability::getDamage() const {
	return this->damage;
}
const AbilityType Ability::getType() const {
	return this->type;
}

Unit* Ability::getOwner() const {
	return this->owner;
}
