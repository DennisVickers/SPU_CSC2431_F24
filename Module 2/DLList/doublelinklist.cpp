#include "doublelinklist.h"
#include <iostream>

/* Done */
// Constructor - Create an empty list
doubleLinkList::doubleLinkList() {
  head = nullptr;
  tail = nullptr;
} 


// Destructor - Release the memory for each node
doubleLinkList::~doubleLinkList() {
  Node* current = head;  // start at the beginning (head) of the list
  while (current != nullptr) {  // keep deleting nodes and shifting to the next node
    head = current->next;  // The new head is the next in the list
    delete current;        // Deallocate the old head
    current = head;        // Reset current to continue the loop (or not)
  }
}

// Insert a node at the beginning of the list
void doubleLinkList::prepend(int payload) {
  // Create a new node
  Node* newNode = new Node(payload);

  // Handle two possibilities. 1) List empty; 2) List not empty
  if (head == nullptr || tail == nullptr) {   // The list is empty
    head = newNode;
    tail = newNode;
  } else {  // Link the new node with the current head
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

// Add a node to the end of the list
void doubleLinkList::append(int payload) {
  // Create a new node
  Node* newNode = new Node(payload);

  // Handle two possibilities. 1) List empty; 2) List not empty
  if (head == nullptr || tail == nullptr) {   // The list is empty
    head = newNode;
    tail = newNode;
  } else {     // List not empty
    newNode->prev = tail;
    newNode->prev->next = newNode;
    tail = newNode;
  }
}

bool doubleLinkList::remove(int data) {
  Node* current = head;    // Start at the beggining

  while (current != nullptr) {
    if (current->payload == data) { // found something to delete
      if (current->prev != nullptr) {
        current->prev->next = current->next;
      } else {   // Removing the head;
        head = current->next;
      }
      if (current->next != nullptr) {
        current->next->prev = current->prev;
      } else {  // delete the tail node
        tail = current->prev;
      }
      delete current;
      return true;
    }
    current = current->next;
  }

  return false;
}

// Look for a matching payload
bool doubleLinkList::search(int data) const {
  Node* current = head;
  while (current != nullptr) {
    if (current->payload = data) {
      return true;
    }
    current = current->next;
  }

  // Nothing found
  return false;
}

void doubleLinkList::showList() const {
  if (head == nullptr) {     // Case 1: The list is empty
    std::cout << "Empty list\n";
  } else {        // Case 2: Show the head, tail and each item in the list
    std::cout << "Head: " << head->payload << std::endl;
    std::cout << "Tail: " << tail->payload << std::endl;
    Node* current= head;   // Start at the begining
    while (current != nullptr) {
      std::cout << current->payload << " -> ";
      current = current->next;
    }
    std::cout << "EOL\n";
  }
}