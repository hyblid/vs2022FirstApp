#include "HeapArray.h"

// ----- CONSTRUCTOR ----- //
HeapArray::HeapArray(const int size) {
	array_size = size;                       // set array size property
	arr = new int[array_size] {0};           // allocate memory on heap
}

// ----- DESTRUCTOR ----- //
HeapArray::~HeapArray() {
	delete[] arr;                          // deallocate memory 
}

// ----- COPY CONSRUCTOR ----- //
HeapArray::HeapArray(const HeapArray& tocopy) {
    array_size = tocopy.array_size;
    arr = new int[array_size];                    // allocate memory for array

    // copy the elements of tobecopied's array (could also use std::copy)
    for (int i = 0; i < array_size; i++) {
        arr[i] = tocopy.arr[i];
    }
}

// ----- COPY ASSIGNMENT ----- //
HeapArray& HeapArray::operator=  (const HeapArray& tocopy) {
    array_size = tocopy.array_size;
    int * new_arr = new int[array_size];

    for (int i = 0; i < array_size; ++i) {
        new_arr[i] = tocopy.arr[i];
    }

    delete[] arr;

    arr = new_arr;

    return *this;
}

// ----- SUBSCRIPT OPERATOR ----- //
int& HeapArray::operator[] (int i) { return arr[i]; }

// ----- MEMBER FUNCTIONS ----- //
int HeapArray::size() const { return array_size; }
int* HeapArray::begin() { return arr; }
int* HeapArray::end() { return arr + array_size; }
