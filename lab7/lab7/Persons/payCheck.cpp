#include "payCheck.h"

PayCheck::PayCheck(const char* newName, int newDate, bool receved) : Person::Person(newName, newDate)
{
	this->moneyDelivered = receved;
}

void PayCheck::print() const
{
	std::cout << "Чек: " << this->name << " от " << date / 10000 << '.' << (date / 100) % 100 << '.' << date % 100 << ';';
	if (moneyDelivered == true)
		std::cout << " Деньги получены";
	else
		std::cout << " Деньги не получены";
	std::cout << std::endl;
}