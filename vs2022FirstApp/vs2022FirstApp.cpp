#include <iostream>
#include <cmath>

void absDiff(int a) {
	int sum = 0;
	sum = (a > 51) ? abs(51 - a) * 3 : abs(51 - a);
	std::cout << "Sum: " << sum << std::endl;
}

int main()
{
	absDiff(53);
	absDiff(30);
	absDiff(51);
	return 0;
}

