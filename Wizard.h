#ifndef WIZARD_H
#define WIZARD_H

#include "Warlocks.h"
#include "Observable.h"

class NoObserverAttachedException;
class CloseQuarterAttack;
class Observer;


class Wizard : public Warlocks, Observable {
public:
	Wizard();
	~Wizard();
	void isAlive();
	void cast(Spellname spellname, Unit* target);
	void attach(Observer* observer);
	void detach(Observer* observer);
	void detachAll();
    void notify();
    void destroy();
};

#endif
