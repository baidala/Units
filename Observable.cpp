#include "Observable.h"

Observable::Observable() {
	//observersList = new list<Observer*>();
}

Observable::~Observable() {}

void Observable::attach(Observer* observer) {
	//observersList->push_front(observer);
	//if ( !(observersList->add(observer)) ) {
	//	throw ChangeListException();
	//}
}
void Observable::detach(Observer* observer) {
	//if( !(observersList->remove(observer)) ) {
	//	throw ChangeListException();
	//}
}
void Observable::notify() {
	/*
	ListIterator* iterator = this->observersList->iterator();
	
	for ( ; !(iterator->over()); ) {
		iterator->getObject()->update(this);
		iterator->next();
	}
	delete iterator;
	*/
}



