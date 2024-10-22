#include "ArrayList.h"
#include <iostream>
using namespace std;

// Constructor
ArrayList::ArrayList(int initial_capacity) : size(0), capacity(initial_capacity) {
    arr = new int[capacity];
}

// Destructor
ArrayList::~ArrayList() {
    delete[] arr;
}

// Private helper function to resize the array
void ArrayList::resize(int new_capacity) {
    int *new_arr = new int[new_capacity];
    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
}

// Insert at the end
void ArrayList::add(int value) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    arr[size++] = value;
}

// Insert at a specific index
void ArrayList::insert(int index, int value) {
    if (index < 0 || index > size) {
        throw out_of_range("Index out of range");
    }
    if (size == capacity) {
        resize(capacity * 2);
    }
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
}

// Remove element at a specific index
void ArrayList::remove(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Access element at a specific index
int ArrayList::get(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return arr[index];
}

// Get the current size of the list
int ArrayList::getSize() const {
    return size;
}

// Get the current capacity of the list
int ArrayList::getCapacity() const {
    return capacity;
}

// Print the list
void ArrayList::print() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
