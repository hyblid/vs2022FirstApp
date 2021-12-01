#include <iostream>
#include <string>
struct Person {
	std::string name;
	int age;
	Person(std::string pName, int pAge) {
		name = pName;
		age = pAge;
	}
};