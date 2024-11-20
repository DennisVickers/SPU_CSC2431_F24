#pragma once

struct Node {
  int data;
  Node* left;
  Node* right;
  Node (int val);
};

class BinarySearchTree {
public:
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(int val);
  bool search(int val);
  void remove(int val);
  void showInOrder();
private:
  Node* root;
  void removeHelper(Node* &root, int val);
  Node* findMin(Node *root);
  void showInOrderHelper(Node *root);
  void deleteTree(Node *root);
};
