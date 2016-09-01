#include "Berserker.h"

Berserker::Berserker()
	: Unit(BERSERKER, new State(100), new CloseQuarterAttack(AXE, this, 50)) {}
	
Berserker::~Berserker() {}

void Berserker::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		this->notify();
		this->detachAll();
		throw UnitIsDeadException();
	}
}

void Berserker::attack(Unit* enemy) {
	isAlive();	
	ability->action(enemy);
}

void Berserker::counterAttack(Unit* enemy) {	
	isAlive();	
	ability->reaction(enemy);
}

void Berserker::takeMagicDamage(int damage) {} 

void Berserker::attach(Observer* observer) {
	this->observersList.push_back(observer);
}

void Berserker::detach(Observer* observer) {
	this->observersList.remove(observer);
}

void Berserker::detachAll() {
	this->observersList.clear();
}

void Berserker::notify() {
	std::list<Observer*>::iterator it = observersList.begin();
	
	for( ; it != observersList.end(); ++it ) {
        (*it)->update(this);
    }
}

void Berserker::destroy() {
	this->~Berserker();
}
