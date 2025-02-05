#pragma once
#include "Person.h"

class wayBill : virtual public Person {
protected:
	bool goodDelivered;
public:
	wayBill() : Person::Person(), goodDelivered(false) {};
	wayBill(const wayBill& rec) : Person::Person(rec), goodDelivered(rec.goodDelivered) {};
	explicit wayBill(const char*, int, bool);
	void print() const override;
};