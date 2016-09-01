#include "Heal.h"

Heal::Heal() : Spell(30, 40) {}

Heal::Heal(int cost, int spellpower) : Spell(cost, spellpower) {}

Heal::~Heal() {}

void Heal::action(Unit* target) {
	target->addHitPoints(spellpower);
}
