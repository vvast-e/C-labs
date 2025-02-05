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
	std::cout << std::endl << "���������: " << this->name << " �� " << date / 10000 << '.' << (date / 100) % 100 << '.' << date % 100 << ';';

	if (goodDelivered == true)
		std::cout << " ����� �������; ";
	else
		std::cout << " ����� �� �������; ";

	if (moneyDelivered == true)
		std::cout << " ������ ��������;";
	else
		std::cout << " ������ �� ��������;";
	std::cout << std::endl;
	std::cout << "����������: " << recipient << "      ���������: " << cost << "$" << std::endl;
}
