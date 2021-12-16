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
#include "Dice.h"
#include "Die.h"
#include "Sample.cpp"
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
	for (int startIndex = 0; startIndex < numberVector.size(); startIndex++)
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

/// when pass array as function argument,
/// it points only first element of array
/// like A[0]
/// 

ostream& operator<<(ostream& COUT, Sample& sample) {
	cout << "sample class's two value : " << sample.getIntA() << ' ' << sample.getIntB() << endl;
	return COUT;
}

/// <<<<<<<<<------------------------------->>>>>>>>>
/// Put code below
/// For exercise C++
/// <<<<<<<<<------------------------------->>>>>>>>>
int sort_descending(int i, int j) {
	return i > j;
}

void display(int value) {
	cout << value << ' ';
}

struct MINScore {
	int minimum;

	MINScore(int number) {
		minimum = number;
	}

	bool operator() (int number) const {
		return number >= minimum;
	}
};

void display_scores(int scores[], int score_count) {
	for (int i = 0; i < score_count; ++i) {
		cout << scores[i] << ' ';
	}
}



struct Entry {
	string name;
	int value;

	Entry read_entry(istream& is) {
		string s;
		int i;
		cin >> s >> i;
		return { s,i };
	}
};

int main() {
	cout << "The Dice Roller program\n";

	for (int i = 6; i > 0; --i) {
		Die die;
		die.set_value(i);
		cout << die.get_image();
	}
	cout << endl;

	// get number of dice from user
	int count;
	cout << "Enter the number of dice to roll: ";
	cin >> count;

	// create Dice object and add Die objects to it
	Dice dice;
	for (int i = 0; i < count; ++i) {
		Die die;
		dice.add_die(die);
	}

	char choice = 'y';
	while (choice == 'y') {
		// roll the dice
		dice.roll_all();
		cout << "YOUR ROLL:\n";
		for (Die die : dice.get_dice()) {
			cout << die.get_image();
		}
		cout << endl;
		cout << "TOTAL: " << dice.get_total() << endl << endl;

		cout << "Roll again? (y/n): ";
		cin >> choice;
	}
	cout << "Bye!\n\n";
}