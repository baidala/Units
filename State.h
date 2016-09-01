#ifndef STATE_H
#define STATE_H

#include <iostream>

class OutOfHitPointsException{};

class State {
public:
	 int hitPoints;        
	 int hitPointsLimit; 
	 int manaPoints;
	 int manaPointsLimit; 
	 State(int hitPoints=100, int manaPoints=0);	
	~State();	
};

#endif //STATE_H
