#include "BinaryTree.h"
#include <iostream>
using namespace std;

Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
   deleteTree(root);
}

void BinaryTree::deleteTree(Node *nodeToRemove) {
   if (nodeToRemove == nullptr) {
      return;  // Base case: If the tree is empty, return.
   }
   // Remove nodes on the left branch
   deleteTree(nodeToRemove->left);
   // Remove nodes on the right branch
   deleteTree(nodeToRemove->right);
   // Delete the node
   delete nodeToRemove;
}

void BinaryTree::insert(int value) {
   //Check to see if the tree is empty, if so, create the root
   if (root == nullptr) {
      root = new Node(value);
      return;
   }

   Node *current = root;
   Node *parent = nullptr;

   while (current != nullptr) {
      parent = current;
      if (value < current->data) {
         current = current->left;
      } else {
         current = current->right;
      }
   }
   if (value < parent->data) {
      parent->left = new Node(value);
   } else {
      parent->right = new Node(value);
   }
}

// Function to perform in-order traversal.
void BinaryTree::inOrderTraversal(Node *currNode) {
   if (currNode == nullptr) {
      return;  // Base case: If the tree is empty, return.
   }
   // Step 1: Recursively traverse the left subtree.
   inOrderTraversal(currNode->left);
   // Step 2: Visit the current node.
   cout << currNode->data << " ";
   // Step 3: Recursively traverse the right subtree.
   inOrderTraversal(currNode->right);
}

void BinaryTree::preOrderTraversal(Node *currNode) {
   if (currNode == nullptr) {
      return; // Base case: If the tree is empty, return.
   }
   // Step 1: Visit the current node.
   cout << currNode->data << " ";
   // Step 2: Recursively traverse the left subtree.
   preOrderTraversal(currNode->left);
   // Step 3: Recursively traverse the right subtree.
   preOrderTraversal(currNode->right);
}

void BinaryTree::postOrderTraversal(Node *currNode) {
   if (currNode == nullptr) {
      return; // Base case: If the tree is empty, return.
   }
   // Step 1: Recursively traverse the left subtree.
   postOrderTraversal(currNode->left);
   // Step 2: Recursively traverse the right subtree.
   postOrderTraversal(currNode->right);
   // Step 3: Visit the current node.
   cout << currNode->data << " ";
}