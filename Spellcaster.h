#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include "Unit.h"
#include "Ability.h"
#include "State.h"
#include "Fireball.h"
#include "Heal.h"
#include "CloseQuarterAttack.h"
#include <map>

enum Spellname {
	FIREBALL,
	HEAL,
	CALL_AZAZEL,
	CALL_BAALZEBUL
};

class OutOfManaException{};
class Spell;

class Spellcaster : public Unit {
protected:
	std::map<Spellname, Spell*>* spellbook;
public:
	Spellcaster(UnitType unitType, State* state, Ability* ability);
	~Spellcaster();

	void spendMana(int amount);
	virtual void cast(Spellname spellname, Unit* target) = 0;
	virtual void destroy() = 0;
};

#endif
