#include "Soldier.h"

Soldier::Soldier()
	: Unit(SOLDIER, new State(100), new CloseQuarterAttack(SWORD, this, 30)) {}
	
Soldier::~Soldier() {}

void Soldier::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		this->notify();
		this->detachAll();
		throw UnitIsDeadException();
	}
}

void Soldier::attack(Unit* enemy) {
	isAlive();	
	ability->action(enemy);
}

void Soldier::counterAttack(Unit* enemy) {	
	isAlive();	
	ability->reaction(enemy); 
}

void Soldier::attach(Observer* observer) {
	this->observersList.push_back(observer);
	
}

void Soldier::detach(Observer* observer) {
	this->observersList.remove(observer);
	
}

void Soldier::detachAll() {
	this->observersList.clear();
}

void Soldier::notify() {
	std::list<Observer*>::iterator it = observersList.begin();
	
	for( ; it != observersList.end(); ++it ) {
        (*it)->update(this);
    }  
	
}
void Soldier::destroy() {
	this->~Soldier();
}
