#include "Priest.h"

Priest::Priest() 
	: Healers(PRIEST, new State(70, 100), new PriestPower(STICK, this, 6)) {}
	
Priest::~Priest() {}

void Priest::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		this->notify();
		this->detachAll();
		throw UnitIsDeadException();
	}
}

void Priest::cast(Spellname spellname, Unit* target) {
	if ((*spellbook)[spellname] != NULL) {
		spendMana((*spellbook)[spellname]->getCost());
		(*spellbook)[spellname]->action(target);
	}
}

void Priest::attack(Unit* enemy) {
	isAlive();	
	ability->action(enemy);
	
}

void Priest::counterAttack(Unit* enemy) {
    isAlive();	
	ability->reaction(enemy);
}

void Priest::attach(Observer* observer) {
	this->observersList.push_back(observer);
}

void Priest::detach(Observer* observer) {
	this->observersList.remove(observer);

}

void Priest::detachAll() {
	this->observersList.clear();
}

void Priest::notify() {
	std::list<Observer*>::iterator it = observersList.begin();
	
	for( ; it != observersList.end(); ++it ) {
        (*it)->update(this);
    }
}
void Priest::destroy() {
	this->~Priest();
}
