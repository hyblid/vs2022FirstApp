// classtst.cpp
#include <iostream>
#include <iomanip>
#include <string>

using std::string;

class food {
private:
	string name;
	string brand;
	int serving_sz;  // in ounces
	int calories;
	float fat_grams;
public:
	food() { std::cout << "default constructing object." << std::endl; };
	~food() { std::cout << "called destructing object." << std::endl; };
	food(string inname, string inbrand, int serving, int incalories, float fat) {
		std::cout << "called constructor." << std::endl;
		name = inname;
		brand = inbrand;
		serving_sz = serving;
		calories = incalories;
		fat_grams = fat;
	}
	void set(string inname, string inbrand, int serving, int incalories, float fat) {
		name = inname;
		brand = inbrand;
		serving_sz = serving;
		calories = incalories;
		fat_grams = fat;
	}
	void display() {
		std::cout << "Food name  : " << name << std::endl;
		std::cout << "     brand : " << brand << std::endl;
		std::cout << " serving_sz: " << serving_sz << std::endl;
		std::cout << "   calories: " << calories << std::endl;
		std::cout << "  fat grams: " << fat_grams << std::endl;
	}
	int get_calories() {
		return calories;
	}
	float get_fat() {
		return fat_grams;
	}
};