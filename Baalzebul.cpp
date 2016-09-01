#include "Baalzebul.h"

Baalzebul::Baalzebul(Unit* master) 
	: Demons(BAALZEBUL, new State(100), new CloseQuarterAttack(AXE, this, 40)) {
		this->master = master;
}

Baalzebul::~Baalzebul() {}

void Baalzebul::attack(Unit* enemy) {
	isAlive();
	if ( enemy != master ) {	
		ability->action(enemy);
	}
	
}

void Baalzebul::counterAttack(Unit* enemy) {
    isAlive();
    if ( enemy != master ) {		
		ability->reaction(enemy);
	}
}

void Baalzebul::destroy() {
	this->~Baalzebul();
}
