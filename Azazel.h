#ifndef AZAZEL_H
#define AZAZEL_H

#include "Demons.h"



class CloseQuarterAttack;
class Observer;


class Azazel : public Demons {
public:
	Azazel(Unit* master);
	~Azazel();
    void attack(Unit* enemy);        
	void counterAttack(Unit* enemy);
	void destroy();
};

#endif
