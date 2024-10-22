#ifndef DLLIST_DOUBLYLINKEDLIST_H
#define DLLIST_DOUBLYLINKEDLIST_H

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data);
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void append(int data);
    void prepend(int data);
    void deleteNode(int data);
    void showList();
    bool search(int data) const;
};

#endif //DLLIST_DOUBLYLINKEDLIST_H
