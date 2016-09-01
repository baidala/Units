#ifndef WARLOCK_H
#define WARLOCK_H

#include "Warlocks.h"
#include "Azazel.h"
#include "Baalzebul.h"
#include "Observable.h"


class NotTheDemonException {};
class Demons;
class Observer;


class Warlock : public Warlocks, Observable {
public:
	Warlock();
	~Warlock();
	void isAlive();
    void cast(Spellname spellname, Unit* target);
	Demons* callInTheDemon(UnitType demon);
	void attach(Observer* observer);
	void detach(Observer* observer);
	void detachAll();
    void notify();
    void destroy();        
};

#endif
