#include "Person.h"
MyVector<Person*> Person::array;

Person::Person() : name(""), date(0){}

Person::Person(const Person& doc) : name(doc.name), date(doc.date) { array.addElement(this); }

Person::Person(const char* newName, const int newDate) : date(newDate) 
{
	setName(newName);
	addPerson(this);
}

Person::~Person() {}

void Person::setName(const char* newName)
{
	const int size = std::strlen(newName) + 1;
	this->name = new char[size];
	std::strncpy(this->name, newName, size);
}

void Person::addPerson(Person* doc)
{
	array.addElement(doc);
}

void Person::print() const
{
	std::cout << "Документ: " << this->name << " от "<< date/10000 << '.' << (date/100)%100 << '.' << date%100 << std::endl;
}

void Person::printArray()
{
	for (int i = 0; i < array.getSize(); i++)
		array[i]->print();
}