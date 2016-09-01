#ifndef BAALZEBUL_H
#define BAALZEBUL_H

#include "Demons.h"


class CloseQuarterAttack;
class Observer;


class Baalzebul : public Demons {
public:
	Baalzebul(Unit* master);
	~Baalzebul();
    void attack(Unit* enemy);        
	void counterAttack(Unit* enemy);
	void destroy();
};

#endif
