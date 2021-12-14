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
#include "Sample.cpp"
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>

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

double calculate_total(int scores[], int score_count);

void display_scores(int scores[], int score_count) {
	for (int i = 0; i < score_count; ++i) {
		cout << scores[i] << ' ';
	}
}

int main() {
	const int cols = 3;
	const int rows = 20;
	int scores[rows][cols]{ 0 };  // set each element in array to 0

	cout << "The Test Scores program\n\n";

	cout << "Enter test scores (" << cols << " per student, " << rows << " max students.)\n"
		<< "Make sure each score is between 0 and 100.\n"
		<< "To end the program, enter -1.\n\n";

	// initialize student counter, score counter, and score variables
	int student_count = 0, score_count = 0, score = 0;

	// prevent out of bounds access by making sure
	// student count is less than the number of rows
	while (score != -1 && student_count < rows) {
		cout << "Student " << (student_count + 1) << endl;
		score_count = 0;
		score = 0;
		// prevent out of bounds access by making sure
		// score count is less than the number of columns
		while (score != -1 && score_count < cols) {
			cout << "Enter score: ";
			cin >> score;

			if (cin.fail()) {
				cin.clear();             // clear bad input flag
				cin.ignore(1000, '\n');  // discard input up to end of line
				cout << "Invalid number. Try again.\n";
			}
			else if (score > 100) {
				cout << "Score must be from 0 to 100. Try again.\n";
			}
			else if (score < -1) {
				cout << "Score can't be a negative number. Try again.\n";
			}
			else if (score > -1) {
				scores[student_count][score_count] = score;   // store score in array
				++score_count;                 // increment score count
			}
		}
		++student_count;
		cout << endl;
	}

	if (student_count == 0) {
		cout << "No scores entered.\n\n";
	}
	else {
		// calculate and display total and average scores
		int row = 0;
		while (row < student_count - 1) {
			cout << "Student " << (row + 1) << ": ";
			display_scores(scores[row], cols);

			double total = calculate_total(scores[row], cols);
			double average = total / cols;
			average = round(average * 10) / 10;
			cout << "\tAvg score: " << average << endl;
			++row;
		}
		cout << endl;
	}
	return 0;
}

double calculate_total(int scores[], int score_count) {
	double total = 0.0;
	for (int i = 0; i < score_count; ++i) {
		total += scores[i];
	}
	return total;
}
