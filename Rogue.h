#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include "RogueAttack.h"
#include "Observable.h"

class Observer;


class Rogue : public Unit, Observable {
public:
	Rogue();
	~Rogue();
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
