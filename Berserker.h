#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include "CloseQuarterAttack.h"
#include "Observable.h"

class Observer;


class Berserker : public Unit, Observable {
public:
	Berserker();
	~Berserker();
	void isAlive();
	void attack(Unit* enemy);        
	void counterAttack(Unit* enemy);
	void takeMagicDamage(int damage);
	void attach(Observer* observer);
	void detach(Observer* observer);
	void detachAll();
    void notify();
    void destroy();
};

#endif
