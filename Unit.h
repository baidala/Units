#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "State.h"
#include "Ability.h"

enum UnitType {
	SOLDIER,
	ROGUE,
	BERSERKER,
	VAMPIRE,
	WEREWOLF,
	WIZARD,
	HEALER,
	PRIEST,
	WARLOCK,
	NECROMANCER,
	AZAZEL,
	BAALZEBUL
	
};


class UnitIsDeadException {};
class State;
class Ability;


class Unit {    
protected:        
	State* state;
	Ability* ability;
	UnitType unitType;
public:        
	Unit(UnitType unitType, State* state, Ability* ability);        
	~Unit();        
	void isAlive();
	const State* getState() const;        
	const Ability* getAbility() const;        
	const UnitType getUnitType() const;        
	void addHitPoints(int hp);        
	void takeDamage(int damage);        
	void takeMagicDamage(int damage);
	virtual void attack(Unit* enemy) = 0;        
	virtual void counterAttack(Unit* enemy) = 0;
	virtual void destroy() = 0;
};

std::ostream& operator<<(std::ostream& out, Unit* unit);

#endif //UNIT_H 
