#pragma once
#include "Person.h"

class PayCheck: virtual public Person {
protected:
	bool moneyDelivered;
public:
	PayCheck() : Person::Person(), moneyDelivered(false) {};
	PayCheck(const PayCheck& rec) : Person::Person(rec), moneyDelivered(rec.moneyDelivered) {};
	explicit PayCheck(const char*, int, bool);
	void print() const override;
};