#ifndef PROTOTYPE_H
#define PROTOTYPE_H

class Prototype {
protected:
	Prototype();
public:	
	~Prototype();	
	virtual Prototype* clone() const = 0;
};

#endif
