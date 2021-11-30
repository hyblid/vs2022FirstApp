export module helloWorld;

import <iostream>;

//public: 
export void HelloWorld();

//private:

void helloWorldImpl();

///
/// IMPLEMENTATION
/// 

void HelloWorld() {
	helloWorldImpl();
}

void helloWorldImpl() {
	std::cout << "Hello, World!" << std::endl;
}