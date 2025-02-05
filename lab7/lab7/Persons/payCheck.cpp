#include "payCheck.h"

PayCheck::PayCheck(const char* newName, int newDate, bool receved) : Person::Person(newName, newDate)
{
	this->moneyDelivered = receved;
}

void PayCheck::print() const
{
	std::cout << "���: " << this->name << " �� " << date / 10000 << '.' << (date / 100) % 100 << '.' << date % 100 << ';';
	if (moneyDelivered == true)
		std::cout << " ������ ��������";
	else
		std::cout << " ������ �� ��������";
	std::cout << std::endl;
}