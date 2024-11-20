#include "BinarySearchTree.h"
#include <iostream>

// Node object constructor
Node::Node(int val) : data(val), left(nullptr), right(nullptr) {}

// Binary Search Tree object constructor
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Binary Search Tree object destructor
BinarySearchTree::~BinarySearchTree() {
  deleteTree(root);
}

void BinarySearchTree::insert(int value) {
  // Check to see if the tree is empty, if so, create the root
  if (root == nullptr) {
    root = new Node(value);
    return;
  }

  Node* current = root;
  Node* parent = nullptr;

  // Find the correct leaf
  while (current != nullptr) {
    parent = current;
    if (value < current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  // Create a new leaf on the left or right
  if (value < parent->data) {
    parent->left = new Node(value);
  } else if (value > parent->data) {
    parent->right = new Node(value);
  }
}

bool BinarySearchTree::search(int value) {
  bool found = false;

  Node* current = root;

  while (!found && current != nullptr) {
    if (value == current->data) {
      found = true;
    } else if (value < current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  return found;
}

void BinarySearchTree::remove(int value) {
  removeHelper(root, value);
}

void BinarySearchTree::removeHelper(Node* &currNode, int value) {
  if (currNode == nullptr) return;  // Base case

  if (value < currNode->data) {
    removeHelper(currNode->left, value);  // Go to the left
  } else if (value > currNode->data) {
    removeHelper(currNode->right, value); // Go to the right
  } else {  // This is the node to remove
    if (currNode->left == nullptr) {
      Node* temp = currNode;
      currNode = currNode->right;
      delete temp;
    } else if (currNode->right == nullptr) {
      Node* temp = currNode;
      currNode = currNode->left;
      delete temp;
    } else {
      Node* temp = findMin(currNode->right);
      currNode->data = temp->data;
      removeHelper(currNode->right, temp->data);
    }
  }
}

Node* BinarySearchTree::findMin(Node* testNode) {
  while (testNode->left != nullptr) {
    testNode = testNode->left;
  }
  
  return testNode;
}

void BinarySearchTree::showInOrder() {
  showInOrderHelper(root);
  std::cout << std::endl;
}

void BinarySearchTree::showInOrderHelper(Node* currNode) {
  if (currNode == nullptr) {
    return;  // Base case: If the tree is empty, return.
  }

  // Step 1: Recursively traverse the left subtree.
  showInOrderHelper(currNode->left);
  // Step 2: Visit the current node.
  std::cout << currNode->data << " ";
  // Step 3: Recursively traverse the right subtree.
  showInOrderHelper(currNode->right);
}

// Recursive function to delete all nodes in the tree
void BinarySearchTree::deleteTree(Node *currNode) {
  if (currNode == nullptr) return;  // Base case

  deleteTree(currNode->left); // Follow the left path
  deleteTree(currNode->right); // Follow the right path
  delete currNode;  // Delete the current node (leaf)
}