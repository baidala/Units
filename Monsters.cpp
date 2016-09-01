#include "Monsters.h"

Monsters::Monsters(UnitType monster, MonstersState* state, MonstersAbility* ability)
	: Unit(monster, state, ability) {}
	
Monsters::~Monsters() {
	this->notify();
	this->detachAll();
}

void Monsters::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		this->notify();
		this->detachAll();
		throw UnitIsDeadException();
	}
}

void Monsters::attack(Unit* enemy) {
	isAlive();	
	ability->action(enemy);
}

void Monsters::counterAttack(Unit* enemy) {
	isAlive();	
	ability->reaction(enemy);
}

void Monsters::attach(Observer* observer) {
	this->observersList.push_back(observer);
	
}

void Monsters::detach(Observer* observer) {
	this->observersList.remove(observer);
	
}

void Monsters::detachAll() {
	this->observersList.clear();
}

void Monsters::notify() {
	std::list<Observer*>::iterator it = observersList.begin();
	
	for( ; it != observersList.end(); ++it ) {
        (*it)->update(this);
    }  
	
}
