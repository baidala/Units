#ifndef PRIEST_H
#define PRIEST_H

#include "Healers.h"
#include "Observable.h"
#include "PriestPower.h"

class Observer;


class Priest : public Healers, Observable {
public:
	Priest();
	~Priest();
	void isAlive();
	void cast(Spellname spellname, Unit* target);
	void attack(Unit* enemy);        
	void counterAttack(Unit* enemy);
	void attach(Observer* observer);
	void detach(Observer* observer);
	void detachAll();
    void notify();
    void destroy();        
};

#endif
