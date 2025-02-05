#include "wayBill.h"

wayBill::wayBill(const char* newName, int newDate, bool receved) : Person::Person(newName, newDate)
{
	this->goodDelivered = receved;
}

void wayBill::print() const
{
	std::cout << "Накладная: " << this->name << " от " << date / 10000 << '.' << (date / 100) % 100 << '.' << date % 100 << ';';
	if (goodDelivered == true)
		std::cout << " Товар получен";
	else
		std::cout << " Товар не получен";
	std::cout << std::endl;
}