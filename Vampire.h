#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Monsters.h"
#include "VampireAttack.h"

class Observer;

class Vampire : public Monsters {
public:
	Vampire();
	~Vampire();
	
	Monsters* biteWound(Unit* enemy);
    Vampire* clone() const;
    void destroy();
};

#endif
