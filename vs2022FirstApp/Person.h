#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <limits>

struct Person {
	std::string name;
	int age;
	Person(std::string pName, int pAge);

	void printStruct(Person& person);
	void printStruct(Person* person);
};
#endif 