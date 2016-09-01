#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "CloseQuarterAttack.h"
#include "Observable.h"

class Observer;


class Soldier : public Unit, Observable {
public:
	Soldier();
	~Soldier();
	void isAlive();
	void attack(Unit* enemy);        
	void counterAttack(Unit* enemy);
	void attach(Observer* observer);
	void detach(Observer* observer);
	void detachAll();
    void notify();
    void destroy();
};

#endif
