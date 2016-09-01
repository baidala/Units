#ifndef WOLFSTATE_H
#define WOLFSTATE_H

#include "MonstersState.h"

class WolfState: public MonstersState {
private:
     WolfState();
     static WolfState* ws_instance;
public:
	 static WolfState* getInstance();
	 ~WolfState();	
};

#endif 
