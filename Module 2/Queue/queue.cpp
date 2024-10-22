#include "queue.h"
#include <iostream>

// Node Constructor
Node::Node(int data) : data(data), next(nullptr) {}

// Queue constructor
Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

Queue::~Queue() {
   Node *nodeToDelete = front;  // Start at the top
   while (nodeToDelete != nullptr) {
      Node *nextInList = nodeToDelete->next;
      delete nodeToDelete;
      nodeToDelete = nextInList;
   }
}

void Queue::enqueue(int data) {
   Node *newNode = new Node(data);
   if (front == nullptr) {
      front = newNode;
      rear = newNode;
   } else {
      rear->next = newNode;
      rear = newNode;
   }
   size++;
}

int Queue::dequeue() {
   if (rear = nullptr) {
      throw std::out_of_range("Attempt to remove a node from an empty queue");
      return -1;
   }

   Node *temp = front;
   int removedData = front->data;
   front = front->next;
   delete temp;
   size--;

   if (front == nullptr) {
      rear = nullptr;
   }

   return removedData;
}

int Queue::peek() const {
   if (front == nullptr) {
      throw std::out_of_range("Attempt to remove a node from an empty queue");
      return -1;
   }
   return front->data;
}

bool Queue::isEmpty() const {
   return front == nullptr;
}

int Queue::getSize() const {
   return size;
}