#pragma once

// Node structure
struct Node {
  int payload;  // payload (or data) for the node
  Node* next;   // pointer to next node
  Node* prev;   // pointer to the previous node
  Node(int val) : payload(val), next(nullptr), prev(nullptr) {}; // Constructor
};

class doubleLinkList {
private:
  Node* head;
  Node* tail;

public:
  doubleLinkList();     // Constructor
  ~doubleLinkList();    // Destructor
  void append(int);
  void prepend(int);
  bool remove(int);
  bool search(int) const;
  void showList() const;
};