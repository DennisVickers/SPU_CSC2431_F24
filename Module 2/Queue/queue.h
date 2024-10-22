#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

// Node structure for Linked List
struct Node {
   int data;
   Node *next;
   Node(int data);
};

class Queue {
   private:
      Node *front;
      Node *rear;
      int size;
   public:
      Queue();
      ~Queue();
      void enqueue(int data);
      int dequeue();
      int peek() const;
      bool isEmpty() const;
      int getSize() const;
};


#endif //QUEUE_QUEUE_H
