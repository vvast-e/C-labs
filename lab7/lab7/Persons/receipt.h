#pragma once
#include "payCheck.h"
#include "wayBill.h"

class Receipt : public PayCheck, public wayBill {
protected:
	float cost;
	char* recipient;
public:
	Receipt() : PayCheck::PayCheck(), wayBill::wayBill(), cost(0), recipient(nullptr) {};
	explicit Receipt(char* newName, int date, bool goodD, bool moneyD, float newCost, char* newRecipient);
	void print() const override;
};