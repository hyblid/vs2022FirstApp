// vs2022FirstApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyLib.h"
#include "Vctr.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <memory>
#include "console.h"
#include "Person.h"
#include "validation.h"
#include <list>

import helloWorld;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void printHelloWorld();
void myPrint();
using namespace std;
using namespace validation;

int recursive_sum(int m, int n) {
	//base case for break recursion
	if (m == n) {
		return m;
	}
	return m + recursive_sum(m + 1, n);
}

bool ascendingCompare(int a, int b) {
	return a < b;
}

bool descendingCompare(int a, int b) {
	return a > b;
}

void customSort(vector<int>& numberVector, bool (*compareFuncPtr)(int, int)) {
	for (int  startIndex = 0 ; startIndex < numberVector.size(); startIndex++)
	{
		int bestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < numberVector.size(); currentIndex++)
		{
			//we are doing comparison here
			if (compareFuncPtr(numberVector[currentIndex], numberVector[bestIndex]))
				bestIndex = currentIndex;
		}
		swap(numberVector[startIndex], numberVector[bestIndex]);
	}
}

void printNumbers(vector<int>& numberVector) {
	for (int i = 0; i < numberVector.size(); i++)
	{
		cout << numberVector[i] << ' ';
	}
}

struct YoutubeChannel {
	std::string name;
	int subscribeCount;
	YoutubeChannel(std::string name, int subscribeCount) {
		this->name = name;
		this->subscribeCount = subscribeCount;
	}
	//1.Error C2676 binary '==': 'const YoutubeChannel' does not define this operator 
	//or a conversion to a type acceptable to the predefined operator vs2022FirstApp
	//2.Error C2678	binary '==': no operator found which takes a left - hand operand of type 'const _Ty' 
	//(or there is no acceptable conversion) -----> add 2 const
	//before remove collection check demand and target are same collection
	bool operator==(const YoutubeChannel& channel) const {
		return this->name == channel.name;
	}
};

struct MyCollection {
	list<YoutubeChannel> myChannels;
	//insert dont need return
	void operator+=(YoutubeChannel& channel) {
		this->myChannels.push_back(channel);
	}
	void operator-=(YoutubeChannel& channel) {
		this->myChannels.remove(channel);
	}
};

ostream& operator<<(ostream& COUT, YoutubeChannel& channel) {
	COUT << "Name: " << channel.name << endl;
	COUT << "Subscribers: " << channel.subscribeCount << endl;
	return COUT;
}

ostream& operator<<(ostream& COUT, MyCollection& collection) {
	for (YoutubeChannel ychannel : collection.myChannels) {
		cout << "Channel Name: " << ychannel.name << endl;
		cout << "Channel subscribes: " << ychannel.subscribeCount << endl;
	}
	return COUT;
}

int main()
{
	cout << "Create Account\n\n";

	// get full name and parse first name
	string full_name;
	string first_name;
	bool valid_name = false;
	while (!valid_name) {
		cout << "Enter full name: ";
		getline(cin, full_name);

		// strip whitespace from front
		int i = full_name.find_first_not_of(" \n\t");
		if (i > -1) {
			full_name = full_name.substr(i);
		}

		// get first name
		int space_index = full_name.find(' ');
		if (space_index == -1) {
			cout << "You must enter your full name. Please try again.\n";
		}
		else {
			first_name = full_name.substr(0, space_index);
			valid_name = true;
		}
	}
	cout << endl;

	// get the password
	string password;
	bool valid_password = false;
	while (!valid_password) {
		// get password
		cout << "Enter password: ";
		getline(cin, password);
		// set valid flag
		valid_password = true;

		// get password
		cout << "Enter password: ";
		getline(cin, password);

		valid_password = is_valid_password(password);
	}
	cout << endl;

	// get the email address
	string email;
	bool valid_email = false;
	while (!valid_email) {
		// get email
		cout << "Enter email: ";
		getline(cin, email);

		valid_email = is_valid_email(email);
	}
	cout << endl;

	// make sure first name uses initial cap
	char letter = first_name[0];
	first_name[0] = toupper(letter);
	for (int i = 1; i < first_name.length(); ++i) {
		letter = first_name[i];
		first_name[i] = tolower(letter);
	}

	// display welcome message
	cout << "Hi " << first_name << ",\n"
		<< "Thanks for creating an account!\n\n";
}


