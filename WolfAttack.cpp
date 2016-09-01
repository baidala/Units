#include "WolfAttack.h"

WolfAttack* WolfAttack::wa_instance = 0;

WolfAttack::WolfAttack(Monsters* owner) 
	: MonstersAbility(FANGS, owner, 40) {}

WolfAttack::~WolfAttack() {}

void WolfAttack::action(Unit* target) {
	target->takeDamage(damage);
	target->isAlive();
	target->counterAttack(this->getOwner());
}

void WolfAttack::reaction(Unit* target) {
	target->isAlive();
    target->takeDamage(this->getDamage() / 2);
    
}

Monsters* WolfAttack::bite(Unit* target) {
	UnitType unitType = target->getUnitType();
	
	target->takeDamage(target->getState()->hitPointsLimit);
	
	if (unitType == VAMPIRE || unitType == WEREWOLF) {
		return NULL;
	}
	
	target->destroy();
	return this->getOwner()->clone();
}

WolfAttack* WolfAttack::getInstance(Monsters* owner) {	
	if( !wa_instance ) {
		wa_instance = new WolfAttack(owner);
	}		
	return wa_instance;	
}
