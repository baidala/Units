#ifndef LOCATION_H
#define LOCATION_H

#include "Unit.h"

class Unit;

class Location {
private:
	int x;
    int y;
    Unit* unit; 
public:
	Location(int x, int y);
	~Location();	
	void addUnit(Unit* unit);
	void clear();
	int getX();
	int getY();
	Unit* getUnit(); 
};
#endif 
