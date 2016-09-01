#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <list>
#include "Observer.h"
//#include "List.h"


class NoObserverAttachedException {};
class ChangeListException {};
class ListIterator;
class List;
class Observer;

class Observable {
protected:
    Observable();
    //List* observersList;
    std::list<Observer*> observersList;
public:	
	~Observable();
		
	virtual void attach(Observer* observer) = 0;
	virtual void detach(Observer* observer) = 0;
	virtual void detachAll() = 0;
	virtual void notify() = 0;
};

#endif
