#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

void get_monthly_weight(string* months, double* weights, int num_months) {
	if (!months || !weights) {
		return;
	}
	for (int i = 0; i < num_months; i++)
	{
			cout << months[i] << ": ";
			cin >> weights[i];
	}
}

double get_total(double* weights, int num_month) {
	double total{ 0.0 };
	for (int i = 0; i < num_month; i++)
	{
		total += weights[i];
	}
	return total;
}

int main()
{
	const int num_months = 12;
	string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	//should define size before compile
	double weights[12]{ 0 };
	double total{ 0.0 };
	double max{ 0.0 };
	double min{ 0.0 };

	cout << "Welcome to the Weight Tracker program!\n\n"
	  	<< "Please enter your weight at the beginning of each month:\n";

	get_monthly_weight(months, weights, num_months);
	total = get_total(weights, num_months);
	cout << "Maximum weight: " << *std::max_element(weights, weights + num_months) << endl;
	cout << "Minimum weight: " << *std::min_element(weights, weights + num_months) << endl;
	cout << "Average weight : " << std::accumulate(weights, weights + num_months,0) / num_months << endl;
}
