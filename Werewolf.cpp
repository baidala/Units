#include "Werewolf.h"

Werewolf::Werewolf()
	: Monsters(WEREWOLF, HumanState::getInstance(), HumanAttack::getInstance(this)) {}
	
Werewolf::~Werewolf() {
	//todo ? ~Monsters();
}

void Werewolf::changeState() {
	if(this->state->isWolf) {
		this->state = HumanState::getInstance();
		this->ability = HumanAttack::getInstance(this);
	} else {
		this->state = WolfState::getInstance();
		this->ability = WolfAttack::getInstance(this);
	}
	
}

Monsters* Werewolf::biteWound(Unit* enemy) {
	Monsters* wf = NULL;
	
	isAlive();
	if (this->state->isWolf) { 
		wf = ability->bite(enemy);	
	}
	return wf;
}



void Werewolf::takeMagicDamage(int damage) {	
	if(this->state->isWolf) {
		takeDamage(damage+5);
	} else {
		takeDamage(damage);
	}
}

Werewolf* Werewolf::clone() const {
	return new Werewolf();
}

void Werewolf::destroy() {
	this->~Werewolf();
}
