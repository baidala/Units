#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <list>
#include "Location.h"

class Location;


class BattleField {
private:
	std::list<Location*> locList;
	int square;
    Location* loc; 
public:
	BattleField(int square);
	~BattleField();	
	void addLoc(Location* loc);
	
	
};
#endif 
