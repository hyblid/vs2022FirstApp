#include <iostream>
class Sample {
private:
	int a;
	int b;
public:
	Sample(int x, int y) : a(x), b(y) {//no body
	};
	Sample() :a(0), b(0) {//no body
	};
	~Sample() {//no body

	};

	int getIntA() {
		return a;
	}

	int getIntB() {
		return b;
	}

	void show_ints(int a, int b) {
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;

	}
};