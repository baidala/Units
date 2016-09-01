#include "Spell.h"

Spell::Spell(int cost, int spellpower) : cost(cost), spellpower(spellpower) {}
Spell::~Spell() {}

const int Spell::getCost() const {
	return cost;
}
const int Spell::getSpellpower() const {
	return spellpower;
}


