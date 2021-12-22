#include <iostream>
#include <string>
#include <algorithm>
#include "MyVector.h"

using namespace std;

template<typename T>
void display(MyVector<T> elements) {   // test copy constructor
    for (T elem : elements) {
        cout << elem << '|';
    }
    cout << endl;
}

int main() {
    cout << "TESTING\n";

    // test initialization list constructor
    MyVector<string> tasks{ "Go to store", "Feed cats", "Check email" };
    cout << "Init:        ";
    display(tasks);                 // test copy constructor
    cout << "capacity():  " << tasks.capacity() << endl;

    // test push_back() function
    cout << "push_back(): ";
    tasks.push_back("Brush teeth");
    display(tasks);                 // test copy constructor
    cout << "capacity():  " << tasks.capacity() << endl;
    cout << "size():      " << tasks.size() << endl;

    // test at() function
    cout << "at(0):       " << tasks.at(0) << endl;
    cout << "at(size-1):  " << tasks.at(tasks.size() - 1) << endl;
    // test resize() function
    cout << "resize(20)\n";
    tasks.resize(20);
    cout << "capacity():  " << tasks.capacity() << endl;
    cout << "size():      " << tasks.size() << endl;
}