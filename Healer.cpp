#include "Healer.h"

Healer::Healer() 
	: Healers(HEALER, new State(70, 100), new CloseQuarterAttack(STICK, this, 8)) {
	Fireball* fr = new Fireball(30, 20);
	Heal* heal = new Heal();
		
	spellbook->insert( std::pair<Spellname, Spell*>(FIREBALL, fr ) );
	spellbook->insert( std::pair<Spellname, Spell*>(HEAL, heal ) );
}
	
Healer::~Healer() {}

void Healer::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		this->notify();
		this->detachAll();
		throw UnitIsDeadException();
	}
}

void Healer::cast(Spellname spellname, Unit* target) {
	if ((*spellbook)[spellname] != NULL) {
		spendMana((*spellbook)[spellname]->getCost());
		(*spellbook)[spellname]->action(target);
	}
}

void Healer::attack(Unit* enemy) {
	isAlive();	
	ability->action(enemy);
	
}

void Healer::counterAttack(Unit* enemy) {
	isAlive();	
	ability->reaction(enemy);
}
void Healer::attach(Observer* observer) {
	this->observersList.push_back(observer);
}

void Healer::detach(Observer* observer) {
	this->observersList.remove(observer);
}

void Healer::detachAll() {
	this->observersList.clear();
}

void Healer::notify() {
	std::list<Observer*>::iterator it = observersList.begin();
	
	for( ; it != observersList.end(); ++it ) {
        (*it)->update(this);
        
    }
}
void Healer::destroy() {
	this->~Healer();
}
