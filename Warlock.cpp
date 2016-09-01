#include "Warlock.h"

Warlock::Warlock() 
	: Warlocks(WARLOCK, new State(70, 100), new CloseQuarterAttack(SWORD, this, 7)) {}
	
Warlock::~Warlock() {}

void Warlock::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		this->notify();
		this->detachAll();
		throw UnitIsDeadException();
	}
}

Demons* Warlock::callInTheDemon(UnitType demon) {
    if( demon == AZAZEL ) {
		return new Azazel(this);
	}
	if( demon == BAALZEBUL ) {
		return new Baalzebul(this);
	} else {
	    throw NotTheDemonException();
	}
    
}

void Warlock::cast(Spellname spellname, Unit* target) {
	if ((*spellbook)[spellname] != NULL) {
		spendMana((*spellbook)[spellname]->getCost());
		(*spellbook)[spellname]->action(target);
	}
}

void Warlock::attach(Observer* observer) {
	this->observersList.push_back(observer);

}

void Warlock::detach(Observer* observer) {
	this->observersList.remove(observer);
}

void Warlock::detachAll() {
	this->observersList.clear();
}

void Warlock::notify() {
	std::list<Observer*>::iterator it = observersList.begin();
	
	for( ; it != observersList.end(); ++it ) {
       (*it)->update(this);
    }
}
void Warlock::destroy() {
	this->~Warlock();
}
