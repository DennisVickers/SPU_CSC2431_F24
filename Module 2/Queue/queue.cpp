#include "queue.h"
#include <iostream>

// Node Constructor
Node::Node(int data) : payload(data), next(nullptr) {};

// Queue constructor
Queue::Queue() : front(nullptr), back(nullptr), size(0) {};

// Queue destructor
Queue::~Queue() {
   Node* current = this->front;  // Start at the beginning
   while (current != nullptr) {
      Node* nextInList = current->next;
      delete current;
      current = nextInList;
   }
}

void Queue::enqueue(int data) {
   Node* newNode = new Node(data);  // Create the new node

   if (this->front == nullptr) {   // List is empty
      this->front = newNode;
      this->back = newNode;
   } else {
      // Update the old last item in the list to point to the new last item
      this->back->next = newNode;
      // Update the pointers to the last item in the list to new item
      this->back = newNode;
   }
   this->size++;
}

int Queue::dequeue() {
   // Make sure the queue isn't empty
   if (this->front == nullptr) {  
      throw std::out_of_range("Attempt to remove a node from an empty queue");
      return -1;
   }

   // Process the dequeue
   // Get the payload from the first item in the list
   int removedData = this->front->payload;
   // Create a temporary pointer to the first item in the list
   Node* temp = this->front;
   // Use the pointer to the from with the next (second) pointer in the list
   this->front = this->front->next;
   // delete the previous first item in the list
   delete temp;

   // Reduce the size of the list
   this->size--;

   // If the list is empty make both location points null
   if (this->front == nullptr) {
      this->back = nullptr;
   }

   return removedData;
}

int Queue::peek() const {
   if (this->front == nullptr) {
      throw std::out_of_range("Attempt to remove a node from an empty queue");
      return -1;
   }
   return this->front->payload;
}

bool Queue::isEmpty() const {
   return (this->front == nullptr);
}

int Queue::getSize() const {
   return this->size;
}