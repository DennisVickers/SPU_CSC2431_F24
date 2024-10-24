#include "singlelinklist.h"
#include <iostream>

// Create an empty list
singleLinkList::singleLinkList() : head(nullptr) {}

// Release memory for all nodes
singleLinkList::~singleLinkList() {
  Node* current = head;  // start at the beginning of the list
  while (current != nullptr) {  // keep deleting nodes and shifting to the next
    Node* nextNode = current->next;
    delete current;
    current = nextNode;
  }
}

// Insert a node at the beginning of the list
void singleLinkList::prepend(int payload) {
  // Create a new node
  Node* newNode = new Node(payload);
  // Replace the new nodes next node with the current head
  newNode->next = head;
  // Make the head the new node
  head = newNode;
}

// Add a node to the end of the list
void singleLinkList::append(int payload) {
  // Create a new node
  Node* newNode = new Node(payload);

  if (head == nullptr) {     // The list is empty
    head = newNode;
  } else {                   // Traverse the current list until the end
    Node* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    // replace next pointer with a pointer to the new node
    current->next = newNode;
  }
}

// remove a node with the specified data
bool singleLinkList::remove(int data) {
    if (head == nullptr) {  // List is empty
      return false;  
    } else if (head->payload == data) {  // delete the head if match
      Node* temp = head;
      head = head->next;
      delete temp;
      return true;
    }
    
    // Search the list until a matching node is found
    Node* current = head;
    while (current->next != nullptr && current->next->payload != data) {
      current = current->next;
    }

    if (current->next == nullptr) {  // No node found
      return false;  
    } else {  // Adjust the links and delete the node      
      Node* temp = current->next;
      current->next = current->next->next;
      delete temp;
      return true;
    }
}

// Check for a match payload
bool singleLinkList::search(int data) const {
  Node* current = head;
  while (current != nullptr) {
    if (current->payload == data) {
      return true;
    }
    current = current->next;
  }

  // Nothing found
  return false;
}

void singleLinkList::showList() const {
  Node* current = head;
  while (current != nullptr) {
    std::cout << current->payload << " -> ";
    current = current->next;
  }
  std::cout << "nullptr" << std::endl;
}