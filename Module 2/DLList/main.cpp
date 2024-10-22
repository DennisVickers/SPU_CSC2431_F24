#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main() {

    DoublyLinkedList list;

    list.prepend(10);
    list.prepend(20);
    list.prepend(30);
    list.showList();

    list.append(40);
    list.append(50);
    list.append(60);
    list.showList();

    list.deleteNode(60);
    list.showList();

    if (list.search(30)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
