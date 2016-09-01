#include "BattleField.h"

BattleField::BattleField(int square){
	this->square = square;
	
	for (int i = 0 ; i < square ; i++){
		for (int j = 0 ; j < square ; i++) {
		loc = new Location(i,j);
		this->addLoc(loc);	
		}
	}	
	
	
}

BattleField::~BattleField(){

}
	
void BattleField::addLoc(Location* loc) {
	this->locList.push_back(loc); 
}
	

