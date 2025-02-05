#include "wayBill.h"

wayBill::wayBill(const char* newName, int newDate, bool receved) : Person::Person(newName, newDate)
{
	this->goodDelivered = receved;
}

void wayBill::print() const
{
	std::cout << "���������: " << this->name << " �� " << date / 10000 << '.' << (date / 100) % 100 << '.' << date % 100 << ';';
	if (goodDelivered == true)
		std::cout << " ����� �������";
	else
		std::cout << " ����� �� �������";
	std::cout << std::endl;
}