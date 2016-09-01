#include "Spellcaster.h"

Spellcaster::Spellcaster(UnitType unitType, State* state, Ability* ability) 
	: Unit(unitType, state, ability) {
		spellbook = new std::map<Spellname, Spell*>();
}

Spellcaster::~Spellcaster() {
	spellbook->clear();
	delete spellbook;
}

void Spellcaster::spendMana(int amount) {
	int newMP = state->manaPoints - amount;
	if ( newMP < 0 ) {
		throw OutOfManaException();
	}
	state->manaPoints = newMP;
}
