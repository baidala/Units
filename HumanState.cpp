#include "HumanState.h"

HumanState* HumanState::hs_instance = 0;

HumanState::HumanState() : MonstersState(150, 0) {
	this->isWolf = false;
}

HumanState::HumanState(int hitPoints, int manaPoints) : MonstersState(hitPoints, manaPoints) {
	this->isWolf = false;
}
HumanState::~HumanState() {}

HumanState* HumanState::getInstance() {	
	if( !hs_instance ) {
		hs_instance = new HumanState();
	}		
	return hs_instance;	
} 
