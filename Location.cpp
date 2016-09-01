#include "Location.h"

Location::Location(int x, int y){
	this->x = x;
	this->y = y;
	this->unit = 0;
}

Location::~Location(){
	this->x = 0;
	this->y = 0;
}
	
void Location::addUnit(Unit* u) {
	this->unit = u;
}
	
void Location::clear(){
	this->unit = NULL;
}
	
int Location::getX(){
	return this->x;
}
	
int Location::getY(){
	return this->y;
}

Unit* Location::getUnit(){
	return this->unit;
}
