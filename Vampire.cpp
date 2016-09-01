#include "Vampire.h"

Vampire::Vampire()
	: Monsters(VAMPIRE, new MonstersState(150, 0), new VampireAttack(FANGS, this, 10)) {}
	
Vampire::~Vampire() {}

Monsters* Vampire::biteWound(Unit* enemy) {
	isAlive();
	return this->ability->bite(enemy);
}


Vampire* Vampire::clone() const {
	return new Vampire();
}

void Vampire::destroy() {
	this->~Vampire();
}
