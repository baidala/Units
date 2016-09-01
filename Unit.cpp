#include "Unit.h"

Unit::Unit(UnitType unitType, State* state, Ability* ability): unitType(unitType), state(state), ability(ability) {}        

Unit::~Unit() {
	delete state;
	delete ability;
}

void Unit::isAlive() {
	if ( this->state->hitPoints < 1 ) {
		throw UnitIsDeadException();
	}
}

const State* Unit::getState() const {
	return this->state;
}

const Ability* Unit::getAbility() const {
	return this->ability;
}


const UnitType Unit::getUnitType() const {
	return this->unitType;
}

void Unit::addHitPoints(int hp) {
    int hpNeeded = this->state->hitPointsLimit - this->state->hitPoints;
    
    this->isAlive();

    if ( hpNeeded > hp ) {
    	this->state->hitPoints += hp;
    } else {
    	this->state->hitPoints += hpNeeded;
    }
    
}

void Unit::takeDamage(int damage) {
	this->isAlive();
	
	if ( this->state->hitPoints > damage ) {
		this->state->hitPoints -= damage;
	} else {
	    this->state->hitPoints = 0;
	}
	
}

void Unit::takeMagicDamage(int damage) {	
	takeDamage(damage);
} 



std::ostream& operator<<(std::ostream& out, Unit* unit) {
	out << "Unit: " << unit->getUnitType() << std::endl;
	out << "hitPoints/hitPointsLimit: " << unit->getState()->hitPoints << "/" << unit->getState()->hitPointsLimit << std::endl;    
	out << "manaPoints/manaPointsLimit: " << unit->getState()->manaPoints << "/" << unit->getState()->manaPointsLimit << std::endl;    
	out << "damage: " << unit->getAbility()->getDamage() << std::endl;
	
	return out;
} 
