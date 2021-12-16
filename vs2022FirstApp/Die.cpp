#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Die.h"

using namespace std;

Die::Die() {
	srand(time(nullptr));  // seed the rand() function
	value = 1;
}

void Die::roll() {
	value = rand() % 6;    // value is >= 0 and < 6
	set_value(++value);
}

int Die::get_value() const {
	return value;
}

void Die::set_value(int num) {
	if (num < 1 || num > 6) {
		throw invalid_argument("Dice number shold be 1-6");
	}
	value = num;
}

string Die::get_image() const {
	string image = "";
	if (value == 6) {
		image = " _____ \n"
			"|o   o|\n"
			"|o   o|\n"
			"|o___o|\n";
	}
	else if (value == 5) {
		image = " _____ \n"
			"|o   o|\n"
			"|  o  |\n"
			"|o___o|\n";
	}
	else if (value == 4) {
		image = " _____ \n"
			"|o   o|\n"
			"|     |\n"
			"|o___o|\n";
	}
	else if (value == 3) {
		image = " _____ \n"
			"|o    |\n"
			"|  o  |\n"
			"|____o|\n";
	}
	else if (value == 2) {
		image = " _____ \n"
			"|o    |\n"
			"|     |\n"
			"|____o|\n";
	}
	else if (value == 1) {
		image = " _____ \n"
			"|     |\n"
			"|  o  |\n"
			"|_____|\n";
	}
	return image;
}