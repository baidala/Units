#include "WolfState.h"

WolfState* WolfState::ws_instance = 0;

WolfState::WolfState() : MonstersState(200, 0) {
	this->isWolf = true;
}

WolfState::~WolfState() {}

WolfState* WolfState::getInstance() {	
	if( !ws_instance ) {
		ws_instance = new WolfState();
	}		
	return ws_instance;	
} 
