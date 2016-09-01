#include "HumanAttack.h"

HumanAttack* HumanAttack::ha_instance = 0;

HumanAttack::HumanAttack(Monsters* owner) 
	: MonstersAbility(FANGS, owner, 20) {}

HumanAttack::~HumanAttack() {}

void HumanAttack::action(Unit* target) {
	target->takeDamage(damage);
	target->isAlive();
	target->counterAttack(this->getOwner());
}

void HumanAttack::reaction(Unit* target) {
	target->isAlive();
    target->takeDamage(this->getDamage() / 2);
    
}

HumanAttack* HumanAttack::getInstance(Monsters* owner) {	
	if( !ha_instance ) {
		ha_instance = new HumanAttack(owner);
	}		
	return ha_instance;	
}

Monsters* HumanAttack::bite(Unit* target) {}
