#ifndef OBSERVER_H
#define OBSERVER_H

#include "Observable.h"

class Observable;

class Observer {
protected:
	Observer();
public:	
	~Observer();	
	virtual void update(const Observable* target) = 0;
	
};

#endif
