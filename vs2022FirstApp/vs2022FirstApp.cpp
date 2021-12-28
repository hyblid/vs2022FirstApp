#include <iostream>

void add(int a, int b) {
	int sum = 0;
	sum = (a == b) ? (a + b) * 3 : (a + b);
	std::cout << sum << std::endl;
}

int main()
{
	add(1, 2);
	add(3, 2);
	add(2, 2);
	return 0;
}

