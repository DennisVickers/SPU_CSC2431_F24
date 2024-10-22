#include "SinglyLinkedList.h"

// Node constructor
Node::Node(int data) : data(data), next(nullptr) {}

// LinkedList constructor
SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr) {}

// LinkedList destructor
SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Append a node at the end
void SinglyLinkedList::append(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Prepend a node at the beginning
void SinglyLinkedList::prepend(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = head;
    }
}

// Delete a node by value
void SinglyLinkedList::deleteNode(int data) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) return;

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    if (current == tail) {
        tail = prev;
    }

    delete current;
}

// Print the list
void SinglyLinkedList::printList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// Search for an element
bool SinglyLinkedList::search(int data) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}
