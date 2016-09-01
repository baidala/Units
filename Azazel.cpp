#include "Azazel.h"

Azazel::Azazel(Unit* master) 
	: Demons(AZAZEL, new State(100), new CloseQuarterAttack(SWORD, this, 40)) {
	this->master = master;
}

Azazel::~Azazel() {}

void Azazel::attack(Unit* enemy) {
	isAlive();
	if ( enemy != master ) {	
		ability->action(enemy);
	}
	
}

void Azazel::counterAttack(Unit* enemy) {
	isAlive();
	if ( enemy != master ) {	
		ability->reaction(enemy);
	}
}

void Azazel::destroy() {
	this->~Azazel();
}
