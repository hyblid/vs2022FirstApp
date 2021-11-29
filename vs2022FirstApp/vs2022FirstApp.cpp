// vs2022FirstApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyLib.h"
#include "Vctr.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

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
	int number = 5;
	char letter = 'a';
	cout << "Hello world";
	print(&number);
	print(&letter);
}
