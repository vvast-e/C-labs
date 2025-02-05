#include "receipt.h"

Receipt::Receipt(char* newName, int date, bool goodD, bool moneyD, float newCost, char* newRecipient) : Person(newName, date)
{
	this->moneyDelivered = moneyD;
	this->goodDelivered = goodD;
	this->cost = newCost;
	const int size = std::strlen(newRecipient) + 1;
	this->recipient = new char[size];
	std::strncpy(this->recipient, newRecipient, size);
}

void Receipt::print() const
{
	std::cout << std::endl << "Квитанция: " << this->name << " от " << date / 10000 << '.' << (date / 100) % 100 << '.' << date % 100 << ';';

	if (goodDelivered == true)
		std::cout << " Товар получен; ";
	else
		std::cout << " Товар не получен; ";

	if (moneyDelivered == true)
		std::cout << " Деньги получены;";
	else
		std::cout << " Деньги не получены;";
	std::cout << std::endl;
	std::cout << "Получатель: " << recipient << "      Стоимость: " << cost << "$" << std::endl;
}
