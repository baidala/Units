#include "Rogue.h"

Rogue::Rogue()
	: Unit(ROGUE, new State(100), new RogueAttack(DAGGER, this, 30)) {}
	
Rogue::~Rogue() {}

void Rogue::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		this->notify();
		this->detachAll();
		throw UnitIsDeadException();
	}
}

void Rogue::attack(Unit* enemy) {
	isAlive();	
	ability->action(enemy);
}

void Rogue::counterAttack(Unit* enemy) {	
	isAlive();	
	ability->reaction(enemy);
}

void Rogue::attach(Observer* observer) {
	this->observersList.push_back(observer);
}

void Rogue::detach(Observer* observer) {
	this->observersList.remove(observer);
}

void Rogue::detachAll() {
	this->observersList.clear();
}

void Rogue::notify() {
	std::list<Observer*>::iterator it = observersList.begin();
	
	for( ; it != observersList.end(); ++it ) {
        (*it)->update(this);
        
    }
}
void Rogue::destroy() {
	this->~Rogue();
}
