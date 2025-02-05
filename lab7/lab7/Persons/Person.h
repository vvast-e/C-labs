#pragma once
#include "D:\labs cLion\lab5new\Containers/MyVector.h"
#include <locale>

class Person {
protected:
	char* name;
	static MyVector<Person *> array;
	int date;
	void setName(const char*);

public:
	Person();
	Person(const Person&);
	Person(const char*, int);
	void addPerson(Person*);
	//void deletePerson();
	virtual ~Person();
	virtual void print() const;
	static void printArray();
};