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
#include "String.cpp"

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
multiset<string> display_and_load_words(string filename);
//map<string, int> get_word_count(const vector<string>& words);
set<string> get_unique_words(multiset<string>& words);

int main() {
	String name;
	String padded_name;
	String quote;
	String reverse_name;

	int index;

	name = (char*)"Michael Dacota";
	quote = (char*)"The C language has brought forth a new era in computing";

	cout << "Name is " << name << endl;
	padded_name.pad('*', 30);
	cout << "Padded Name is " << padded_name << endl;

	cout << "the length of:" << endl;
	cout << "<" << quote << ">" << " is " << quote.slen() << endl;
	index = quote.search((char*)"forth");

	if (index != -1) {
		cout << "The index of \"forth\" in " << endl << quote;
		cout << " is " << index << endl;
	}
	else {
		cout << "forth is not in " << endl << quote << endl;
	}
	reverse_name = name.reverse();
	cout << "My name is " << name << endl;
	cout << "My reverse name is " << reverse_name << endl;
}

multiset<string> display_and_load_words(string filename) {
	multiset<string> words;
	ifstream infile(filename);

	if (infile) {
		string word;
		while (infile >> word) {

			string new_word = "";
			for (char c : word) {
				if (c == '.' || c == ',') {
					continue;               // remove punctuation
				}
				else if (isupper(c)) {
					new_word += tolower(c); // convert to lowercase
				}
				else {
					new_word += c;
				}
			}
			cout << new_word << ' ';
			words.insert(new_word);      // add word 
		}
		infile.close();
	}

	cout << endl;
	auto itr = words.begin();
	for (itr = words.begin(); itr != words.end(); itr++)
	{
		cout << (*itr);
	}
	return words;
}

set<string> get_unique_words(multiset<string>& words) {
	set<string> unique_words;

	for (string word : words) {
		auto search = unique_words.find(word);
		if (search == unique_words.end()) {
			unique_words.insert(word);
		}
	}
	return unique_words;
}