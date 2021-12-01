#include <iostream>
#include <string>
#include "Person.h"

Person::Person(std::string pName, int pAge) {
	name = pName;
	age = pAge;
}

void Person::printStruct(Person& person) {
	std::cout << "Person name: " << person.name << std::endl;
	std::cout << "Person age: " << person.age << std::endl;
}

void Person::printStruct(Person* person) {
	std::cout << "Person name: " << person->name << std::endl;
	std::cout << "Person age: " << (*person).age << std::endl;
}