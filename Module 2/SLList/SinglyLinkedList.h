#ifndef SLLIST_SINGLYLINKEDLIST_H
#define SLLIST_SINGLYLINKEDLIST_H

#include <iostream>

// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;
    Node(int data);
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void append(int data);
    void prepend(int data);
    void deleteNode(int data);
    void printList();
    bool search(int data) const;
};

#endif //SLLIST_SINGLYLINKEDLIST_H
