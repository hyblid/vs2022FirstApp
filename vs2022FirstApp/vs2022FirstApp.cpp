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

struct Movie {
	string name;
};

void printCollection(const Movie& moive) {
	cout << moive.name << endl;
}

/// when pass array as function argument,
/// it points only first element of array
/// like A[0]
/// 

ostream& operator<<(ostream& COUT, Sample& sample) {
	cout << "sample class's two value : " << sample.getIntA() << ' ' << sample.getIntB() << endl;
	return COUT;
}

int main()
{
	int sales[3][4] = { {10,22,43,22}, 
		                {33,11,43,55},
		                {54,56,76,59} };
	//int* ip = (int*)sales[0];
	int* ip = (int*)sales;
	int** ipp; //wrong

	cout << "Storage of data:" << endl;
	for (int i = 0; i < 12; i++) {
		cout << ip[i] << " ";
	}

	int(*ip4)[4] = sales; //ip4 points to array of ints
	//ip4 = &sales[0]; //address of first sales
	//ip4 = sales;
	cout << endl << endl;
	cout << "Matrix concept1:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++) {
			cout << *(*(ip4 + i) + j) << " ";
		}
		cout << endl;
	}
}

