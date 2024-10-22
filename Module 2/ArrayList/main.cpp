#include "ArrayList.h"
#include <iostream>
using namespace std;

int main() {
	// Create the list
    ArrayList myList;

    // Testing add
    myList.add(1);
    myList.add(2);
    myList.add(3);

    // Print the list
    myList.print();

    // Test insert
    myList.insert(1, 43);

    // Testing remove
    myList.remove(1);

    // Testing get
    cout << "Element at index 1: " << myList.get(1) << endl;


    return 0;
}
