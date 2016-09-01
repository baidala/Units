#include "Fireball.h"

Fireball::Fireball() : Spell(30, 40) {}

Fireball::Fireball(int cost, int spellpower) : Spell(cost, spellpower) {}

Fireball::~Fireball() {}

void Fireball::action(Unit* target) {
	target->takeMagicDamage(spellpower);
}
