#include "Healers.h"

Healers::Healers(UnitType unitType, State* state, Ability* ability) 
	: Spellcaster(unitType, state, ability) {
    
    Fireball* fr = new Fireball(30, 20);
    Heal* heal = new Heal();
    				
    spellbook->insert( std::pair<Spellname, Spell*>(FIREBALL, fr ) );		
    spellbook->insert( std::pair<Spellname, Spell*>(HEAL, heal ) ); 
}
	
Healers::~Healers() {}

void Healers::cast(Spellname spellname, Unit* target) {
	if ((*spellbook)[spellname] != NULL) {
		spendMana((*spellbook)[spellname]->getCost());
		(*spellbook)[spellname]->action(target);
	}
}

void Healers::attack(Unit* enemy) {
	isAlive();	
	ability->action(enemy);
	
}

void Healers::counterAttack(Unit* enemy) {
    isAlive();	
	ability->reaction(enemy);
}
