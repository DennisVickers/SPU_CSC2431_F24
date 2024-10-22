#include "stack.h"
#include <iostream>
using namespace std;

// Node Constructor
Node::Node(int data) : data(data), next(nullptr) {}

// Stack Constructor
Stack::Stack() : top(nullptr) {}

// Stack Destructor
Stack::~Stack() {
   Node *current = top;
   while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
   }
}

// Push operation
void Stack::push(int data) {
   Node* newNode = new Node(data);
   newNode->next = top;
   top = newNode;
}

// Pop operation
int Stack::pop() {
   if (top == nullptr) {
      cout << "Stack Underflow" << endl;
      return -1;  // Indicate an error
   }
   int poppedData = top->data;
   Node *temp = top;
   top = top->next;
   delete temp;
   return poppedData;
}

// Peek operation
int Stack::peek() const {
   if (top == nullptr) {
      cout << "Stack is empty" << endl;
      return -1;  // Indicate an error
   }
   return top->data;
}

// Search for an element
int Stack::search(int data) const {
   int location = 0;
   Node* current = top;
   while (current != nullptr) {
      if (current->data == data) {
         return location;
      }
      location++;
      current = current->next;
   }
   return -1; // data not found
}

// Check if stack is empty
bool Stack::isEmpty() const {
   return top == nullptr;
}
