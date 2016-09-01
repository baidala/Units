#include "Necromancer.h"


Necromancer::Necromancer() 
	: Warlocks(NECROMANCER, new State(70, 100), new CloseQuarterAttack(STICK, this, 10)) {}
	
Necromancer::~Necromancer() {}

void Necromancer::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		this->detachAll();
		throw UnitIsDeadException();
	}
}

void Necromancer::cast(Spellname spellname, Unit* unit) {
	Observable* target = reinterpret_cast<Observable*>(unit);
	
	if ((*spellbook)[spellname] != NULL) {
		spendMana((*spellbook)[spellname]->getCost());
		(*spellbook)[spellname]->action(unit);
		addTarget(target);
	}
}

void Necromancer::update(Unit* unit) {
	Observable* target = reinterpret_cast<Observable*>(unit);
	
	this->addHitPoints(unit->getState()->hitPointsLimit / 5);
	this->targetsList.remove(target);
}

void Necromancer::detachAll() {
	std::list<Observable*>::iterator it = targetsList.begin();
	
	for( ; it != targetsList.end(); ++it ) {
        (*it)->detach(this);
    }
    this->targetsList.clear(); 
}

void Necromancer::addTarget(Observable* target) {
	this->targetsList.push_back(target);
	this->targetsList.unique();  
}

void Necromancer::attack(Unit* enemy) {
	Observable* target = reinterpret_cast<Observable*>(enemy);
	
	isAlive();
	ability->action(enemy);
	addTarget(target);
}

void Necromancer::counterAttack(Unit* enemy) {    
	Observable* target = reinterpret_cast<Observable*>(enemy);
	
	isAlive();		
	ability->reaction(enemy);
	addTarget(target);
}

void Necromancer::destroy() {
	this->~Necromancer();
}
