#pragma once

enum Color {RED, BLACK};

struct Node {
   int data;
   bool color;
   Node* left;
   Node* right; 
   Node* parent;

   // Constructor
   Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {};
};

class RBTree {
public:
   RBTree();
   ~RBTree();
   void insert(int data);
   void remove(int data);
   void inorder();
   void levelOrder();

private:
   Node* root;
   void insertFix(Node*);
   void deleteFix(Node*);
   void rotateLeft(Node*);
   void rotateRight(Node*);
   Node* findMin(Node*);
   Node* search(int);
   void inorderHelper(Node*);
   void levelOrderHelper(Node*);
   void releaseMemory(Node*);
};
