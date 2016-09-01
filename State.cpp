#include "State.h"

State::State(int hitPoints, int manaPoints) {
	this->hitPoints = hitPoints;
	this->hitPointsLimit = hitPoints;
	this->manaPoints = manaPoints;
	this->manaPointsLimit = manaPoints;
	
}
State::~State() {}
