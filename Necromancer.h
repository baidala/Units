#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "Warlocks.h"
#include "Observer.h"

class NoObserverAttachedException;
class CloseQuarterAttack;


class Necromancer : public Warlocks, Observer {
private:
	std::list<Observable*> targetsList;
	void addTarget(Observable*);
public:
	Necromancer();
	~Necromancer();
	void isAlive();
	void cast(Spellname spellname, Unit* target);
	void update(Unit* target);
	void detachAll();
	void attack(Unit* enemy);
	void counterAttack(Unit* enemy);
	void destroy();
	      
};

#endif
