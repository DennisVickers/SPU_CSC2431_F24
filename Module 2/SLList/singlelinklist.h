#pragma once

// Node structure
struct Node {
  int payload;    // payload for node
  Node* next;  // pointer to next node
  Node(int val) : payload(val), next(nullptr) {};  // Constructor
};

class singleLinkList {
private:
  Node* head;

public:
  singleLinkList();              // linked list constructor
  ~singleLinkList();             // linked list destructor
  void append(int);
  void prepend(int);
  bool remove(int);
  bool search(int) const;
  void showList() const;
};