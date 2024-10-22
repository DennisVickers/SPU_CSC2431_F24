#ifndef STACK_STACK_H
#define STACK_STACK_H

// Node class to represent each element in the stack
struct Node {
   int data;
   Node *next;
   Node(int data);
};

// Stack class using a linked list
class Stack {
private:
   Node *top;
public:
   Stack();
   ~Stack();
   void push(int data);
   int pop();
   int peek() const;
   int search(int data) const;
   bool isEmpty() const;
};

#endif //STACK_STACK_H
