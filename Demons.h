#ifndef DEMONS_H
#define DEMONS_H

#include "Unit.h"
#include "CloseQuarterAttack.h"
#include "State.h"
#include "Observable.h"

class CloseQuarterAttack;
class Observer;

class Demons : public Unit, Observable {
protected:	
	Unit* master;
	Demons(UnitType demon, State* state, Ability* ability); 
public:
	~Demons();
    virtual void attack(Unit* enemy) = 0;        
	virtual void counterAttack(Unit* enemy) = 0;
	void isAlive();
	void attach(Observer* observer);
	void detach(Observer* observer);
	void detachAll();
	void notify();
	virtual void destroy() = 0;
};

#endif
