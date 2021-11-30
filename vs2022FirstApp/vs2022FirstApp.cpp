// vs2022FirstApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyLib.h"
#include "Vctr.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int recursive_sum(int m, int n) {
	//base case for break recursion
	if (m == n) {
		return m;
	}
	return m + recursive_sum(m + 1, n);
}

template<typename T>
void print(T* ptr) {
	cout << "value of ptr= " << *ptr << endl;
}
int main()
{
	///For DLL example
	//std::cout << "Max_size : " <<  max_size << std::endl;
	//Vctr v(2, 3, 4);
	//std::cout << v << std::endl;
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

        // set valid flag
        valid_password = true;

        // get password
        cout << "Enter password: ";
        getline(cin, password);

        // make sure password has at least 8 characters
        if (password.length() < 8) {
            cout << "Password must be at least 8 characters.\n";
            valid_password = false;
        }

        // make sure password includes a number
        int index = password.find_first_of("0123456789");
        if (index == -1) {
            cout << "Password must include a number.\n";
            valid_password = false;
        }

        // make sure password includes a special character
        bool special_character = false;
        for (char c : password) {
            if (ispunct(c)) {
                special_character = true;
                break;                      // exit for loop
            }
        }
        if (!special_character) {
            cout << "Password must include a special character.\n";
            valid_password = false;
        }

        // display message if password is not valid
        if (!valid_password) {
            cout << "Please try again.\n";
        }
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
