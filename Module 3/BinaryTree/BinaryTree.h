#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

struct Node {
   int data;
   Node *left;
   Node *right;
   Node(int value);
};

class BinaryTree {
public:
   Node* root;

   BinaryTree();
   ~BinaryTree();
   void deleteTree(Node *node);

   void insert(int value);
   void inOrderTraversal(Node *node);
   void preOrderTraversal(Node *node);
   void postOrderTraversal(Node *node);
};

#endif //BINARYTREE_BINARYTREE_H
