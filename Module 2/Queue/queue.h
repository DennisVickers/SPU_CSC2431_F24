#pragma once

// Node structure for Linked List
struct Node {
   int payload;
   Node* next;
   Node(int);
};

class Queue {
   private:
      Node* front;
      Node* back;
      int size;
   public:
      Queue();
      ~Queue();
      void enqueue(int);
      int dequeue();
      int peek() const;
      bool isEmpty() const;
      int getSize() const;
};
