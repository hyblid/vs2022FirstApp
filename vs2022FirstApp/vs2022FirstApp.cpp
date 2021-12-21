#include <iostream>
#include "sort.cpp"

using namespace std;


int main()
{
	SORT s;
	const int size = 5;
	int temps[size] = { 75, 64, 92, 88, 57 };
	cout << "Temperatures: ";
	for (int temp : temps) {
		cout << temp << ' ';
	}
	cout << endl;

	s.bubble_sort(temps, size);
	cout << "Sorted temperatures: ";
	for (int temp : temps) {
		cout << temp << ' ';
	}
	cout << endl << endl;

	double prices[size] = { 18.99, 9.99, 12.99, 24.99, 15.99 };
	cout << "Prices: ";
	for (double price : prices) {
		cout << price << ' ';
	}
	cout << endl;
	// code to sort and print array
	s.bubble_sort(prices, size);
	cout << "Prices: ";
	for (double price : prices) {
		cout << price << ' ';
	}
	return 0;
}


