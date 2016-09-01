#include "Wizard.h"


Wizard::Wizard() 
	: Warlocks(WIZARD, new State(70, 100), new CloseQuarterAttack(STICK, this, 10)) {}
	
Wizard::~Wizard() {}

void Wizard::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		this->notify();
		this->detachAll();
		throw UnitIsDeadException();
	}
}

void Wizard::cast(Spellname spellname, Unit* target) {
	if ((*spellbook)[spellname] != NULL) {
		spendMana((*spellbook)[spellname]->getCost());
		(*spellbook)[spellname]->action(target);
	}
}

void Wizard::attach(Observer* observer) {
	this->observersList.push_back(observer);
}

void Wizard::detach(Observer* observer) {
	this->observersList.remove(observer);
}

void Wizard::detachAll() {
	this->observersList.clear();
}

void Wizard::notify() {
	std::list<Observer*>::iterator it = observersList.begin();
	
	for( ; it != observersList.end(); ++it ) {
       (*it)->update(this);
    }
}

void Wizard::destroy() {
	this->~Wizard();
}
