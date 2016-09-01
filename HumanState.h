#ifndef HUMAN_STATE_H
#define HUMAN_STATE_H

#include "MonstersState.h"

class HumanState: public MonstersState {
private:
     HumanState();
     HumanState(int hitPoints, int manaPoints);
     static HumanState* hs_instance;
public:
	 static HumanState* getInstance();
	 ~HumanState();	
};

#endif 
