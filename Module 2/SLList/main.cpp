#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    SinglyLinkedList list;

    list.prepend(10);
    list.prepend(20);
    list.append(30);

    list.printList();  // Output should be "20 10 30"

    list.deleteNode(20);
    list.printList();  // Output should be "10 30"

    if (list.search(30)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}