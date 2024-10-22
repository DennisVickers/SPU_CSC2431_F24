#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

// Node constructor
Node::Node(int data) : data(data), next(nullptr), prev(nullptr) {}

// LinkedList constructor
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// LinkedList destructor
DoublyLinkedList::~DoublyLinkedList() {
    Node* temp = head;
    // Do until the end of the list
    while (temp != nullptr) {
        head = head->next;  // The new head is the next in the list
        delete temp;        // Deallocate the old head
        temp = head;        // Reset temp to continue the loop (or not)
    }
}

// Append a node at the end
void DoublyLinkedList::append(int data) {
    // create a new node;
    Node* newNode = new Node(data);
    newNode->next = nullptr;

    /* Deal with two cases:
    * Case 1 - The list is empty
    * Case 2 - The list is not empty
    */
    if (head == nullptr) {   // Case 1
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    } else {                 // Case 2
        newNode->prev = tail;
        newNode->prev->next = newNode;
        tail = newNode;
    }
}

// Prepend a node at the beginning
void DoublyLinkedList::prepend(int data) {

    // Create a new node
    Node *newNode = new Node(data);
    newNode->prev = nullptr;

    /* Deal with two cases:
     * Case 1 - The list is empty
     * Case 2 - The list is not empty
     */
    if (head == nullptr) { // Case 1
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
    } else {               // Case 2
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Delete a node by value
/*
 * Step 1 - Make sure the list isn't empty
 * Step 2 - Find the item to delete
 * Step 3 - If an item is found, update the points
 * Step 4 - If an item is found, delete it
 */
void DoublyLinkedList::deleteNode(int data) {

    // Step 1
    if (head == nullptr) {return;}

    // Step 2
    Node *nodeToRemove = nullptr;
    Node *currNode = head;  // Start at the beginning
    while (currNode != nullptr) {
        if (currNode->data == data) {
            nodeToRemove = currNode;
            break;
        }
        currNode = currNode->next;
    }

    if (nodeToRemove == nullptr) { // Node wasn't found
        std::cout << data << " not found" << std::endl;
        return;
    }

    cout << "Data to delete: " << nodeToRemove->data << endl;

    // Step 3
    if (nodeToRemove == head) { // Node to delete is first node in list
        head = nodeToRemove->next;
        nodeToRemove->next->prev = head;
    } else if (nodeToRemove == tail) { // Node to delete is last node in list
        tail = nodeToRemove->prev;
        nodeToRemove->prev->next = nullptr;
    } else { // Node to delete is in the middle of the list
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
    }

    // Step 4
    delete nodeToRemove;
}

// Print the list
void DoublyLinkedList::showList() {
    if (head == nullptr) {
        std::cout << "Empty list" << std::endl;
        return;
    }
    Node* current = head;
    std::cout << "Head:" << head->data << std::endl;
    std::cout << "Tail:" << tail->data << std::endl;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// Search for an element
bool DoublyLinkedList::search(int data) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}
