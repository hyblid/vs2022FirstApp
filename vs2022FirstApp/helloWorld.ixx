export module helloWorld;

import <iostream>;

//public: 
export void HelloWorld();

//private:
void helloWorldImpl();

///
/// IMPLEMENTATION
/// 

//public:
void HelloWorld() {
	helloWorldImpl();
}

//private:
void helloWorldImpl() {
	std::cout << "Hello, World!" << std::endl;
}