#include "Demons.h"

Demons::Demons(UnitType demon, State* state, Ability* ability) 
	: Unit(demon, state, ability) {
}

Demons::~Demons() {}

void Demons::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		this->notify();
		this->detachAll();
		throw UnitIsDeadException();	
	}
}

void Demons::attack(Unit* enemy) {
	isAlive();
	if ( enemy != master ) {
		ability->action(enemy);
	}
}

void Demons::counterAttack(Unit* enemy) {
    isAlive();
    if ( enemy != master ) {
    	ability->reaction(enemy);
    }
}

void Demons::attach(Observer* observer) {
	this->observersList.push_back(observer);
}

void Demons::detach(Observer* observer) {
	this->observersList.remove(observer);
}

void Demons::detachAll() {
	this->observersList.clear();
}

void Demons::notify() {
	std::list<Observer*>::iterator it = observersList.begin();
	for( ; it != observersList.end(); ++it ) {
		(*it)->update(this);
	}
} 
