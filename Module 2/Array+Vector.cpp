#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Array Example
    const int arraySize = 5;
    int numbersArray[arraySize] = {10, 20, 30, 40, 50};

    cout << "Array elements:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << "Element " << i << ": " << numbersArray[i] << endl;
    }

    // Modify an element in the array
    numbersArray[2] = 100;
    cout << "After modifying the array, element 2: " << numbersArray[2] << endl;

    // Vector Example
    vector<int> numbersVector = {10, 20, 30, 40, 50};

    cout << "\nVector elements:" << endl;
    for (size_t i = 0; i < numbersVector.size(); ++i) {
        cout << "Element " << i << ": " << numbersVector[i] << endl;
    }

    // Modify an element in the vector
    numbersVector[2] = 100;
    cout << "After modifying the vector, element 2: " << numbersVector[2] << endl;

    // Add an element to the vector
    numbersVector.push_back(60);
    cout << "After adding an element to the vector, new size: " << numbersVector.size() << endl;

    cout << "Vector elements after adding an element:" << endl;
    for (size_t i = 0; i < numbersVector.size(); ++i) {
        cout << "Element " << i << ": " << numbersVector[i] << endl;
    }

    return 0;
}
