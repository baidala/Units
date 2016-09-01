#ifndef MONSTERS_H
#define MONSTERS_H

#include "Unit.h"
#include "Observable.h"
#include "Prototype.h"
#include "MonstersAbility.h"
#include "MonstersState.h"

class Observer;
class MonstersAbility;
class MonstersState;


class Monsters : public Unit, Observable, Prototype {
protected:
	MonstersAbility* ability;
	MonstersState* state;
	Monsters(UnitType monster, MonstersState* state, MonstersAbility* ability);
public:
	~Monsters();
	void isAlive();
	void attack(Unit* enemy);        
	void counterAttack(Unit* enemy);
	virtual Monsters* biteWound(Unit* enemy) = 0;        
	void attach(Observer* observer);
	void detach(Observer* observer);
	void detachAll();
    void notify();
    virtual Monsters* clone() const = 0;
    virtual void destroy() = 0;
};

#endif
