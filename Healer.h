#ifndef HEALER_H
#define HEALER_H

#include "Healers.h"
#include "Observable.h"

class Observer;


class Healer : public Healers, Observable {
public:
	Healer();
	~Healer();
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
