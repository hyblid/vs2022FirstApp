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
#include "Account.cpp"

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
const string accounts_file = "accounts.txt";

void display_accounts(const vector<Account>& accounts) {
	cout << left << setw(30) << "Name" << left<< setw(40) << "Email" << endl;
	for (Account account : accounts) {
		cout << left << setw(30) << account.first_name + ' ' + account.last_name << left << setw(40) << account.email << endl;
	}

}

void write_accounts_to_file(const vector<Account>& accounts) {
	ofstream output_file(accounts_file);
	for (Account account : accounts) {
		output_file << account.first_name << '\t' << account.last_name << '\t' << account.password << '\t' << account.email << endl;
	}
	output_file.close();
}

vector<Account> read_accounts_from_file() {
	vector<Account> accounts;
	Account account;
	ifstream input_file(accounts_file);
	if (input_file) {
	while (input_file >> account.first_name >> account.last_name >> account.password >> account.email) {
		accounts.push_back(account);
		}
		input_file.close();
	}
	cout << endl;
	return accounts;
}

Account get_account() {
	Account account;
	cout << "First name: ";
	getline(cin, account.first_name);
	cout << "Last name: ";
	getline(cin, account.last_name);
	cout << "Password: ";
	getline(cin, account.password);
	cout << "Email: ";
	getline(cin, account.email);
	return account;
}

int main()
{
	vector<Account> accounts = read_accounts_from_file();
	display_accounts(accounts);
	bool isExist = false;
	char another = 'y';
	while (tolower(another) == 'y') {
		Account account = get_account();
		for (Account ac : accounts) {
			if (account.email == ac.email) {
				isExist = true;
				break;
			} 
		}
    
		if (isExist) {
			cout << account.email << " alreay exists - account not added" << endl;
		}
		else {
			accounts.push_back(account);
			cout << account.email << " was added for " << account.first_name << ' ' << account.last_name << endl;
	        write_accounts_to_file(accounts);
		}


		cout << "Enter another account? (y/n): ";
		cin >> another;
		cin.ignore();
		cout << endl;
	}
	display_accounts(accounts);
}
