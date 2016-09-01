#ifndef MONSTERS_STATE_H
#define MONSTERS_STATE_H

#include "State.h"

class MonstersState : public State {
public:
	 bool isWolf; 
	 MonstersState(int hitPoints, int manaPoints);	
	~MonstersState();	
};

#endif
