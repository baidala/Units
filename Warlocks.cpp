#include "Warlocks.h"

Warlocks::Warlocks(UnitType unitType, State* state, Ability* ability) 
	: Spellcaster(unitType, state, ability) {
    
    Fireball* fr = new Fireball();
    Heal* heal = new Heal(30,20);
    				
    spellbook->insert( std::pair<Spellname, Spell*>(FIREBALL, fr ) );		
    spellbook->insert( std::pair<Spellname, Spell*>(HEAL, heal ) ); 
}
	
Warlocks::~Warlocks() {}

void Warlocks::cast(Spellname spellname, Unit* target) {
	if ((*spellbook)[spellname] != NULL) {
		spendMana((*spellbook)[spellname]->getCost());
		(*spellbook)[spellname]->action(target);
	}
}

void Warlocks::attack(Unit* enemy) {
	isAlive();	
	ability->action(enemy);
	
}

void Warlocks::counterAttack(Unit* enemy) {
    isAlive();	
	ability->reaction(enemy);
}
