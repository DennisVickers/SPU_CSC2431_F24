#include "avl.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void AVLTree::insert(int newData) {
   Node* newNode = insertHelper(newData);
   Node* temp = balance(newNode);
   return;
}

bool AVLTree::search(int key) {
   bool found = searchHelper(root, key);
   return found;
}

bool AVLTree::validate() {
   bool valid = validateHelper(root);
   return valid;
}

string AVLTree::inOrder() {
   string outString = "";
   inorderHelper(root, outString);
   return outString;
}

void AVLTree::inorderHelper(Node* node, string& outString) {
   // Base case, at a leaf or empty tree
   if (node == nullptr) return;

   // Traverse left subtree
   inorderHelper(node->left, outString);
   // Process current node
   // std::cout << node->data << " ";
   outString += (to_string(node->data) + " ");
   // Traverse the right subtree
   inorderHelper(node->right, outString);

   return;
}

bool AVLTree::searchHelper(Node* node, int key) {
   if (!node) return false;
   if (node->data == key) return true;
   if (key < node->data) return searchHelper(node->left, key);
   return searchHelper(node->right, key);
}

bool AVLTree::validateHelper(Node* node) {
   if (node == nullptr) {
      return true;
   }

   int balanceFactor = getBalanceFactor(node);
   if (balanceFactor < -1 || balanceFactor > 1) {
      return false;
   }

   return validateHelper(node->left) && validateHelper(node->right);

}

int AVLTree::height(Node* node) {
   int ht = 0;
   if (node != nullptr) {
      ht = node->height;
   }
   return ht;
}

int AVLTree::getBalanceFactor(Node* node) {
   int bf = 0;
   if (node != nullptr) {
      bf = (height(node->left) - height(node->right));
   }
   return bf;
}

Node* AVLTree::balance(Node* node) {
   if (node == nullptr) return node;

   node->height = 1 + max(height(node->left), height(node->right));

   int balanceFactor = getBalanceFactor(node);

   if (balanceFactor > 1) {
      if (getBalanceFactor(node->left) < 0) {
         node->left = leftRotate(node->left);
      }
      return rightRotate(node);
   }
   if (balanceFactor < -1) {
      if (getBalanceFactor(node->right) > 0) {
         node->right = rightRotate(node->right);
      }
      return leftRotate(node);
   } 
 
   return node;
}

Node* AVLTree::leftRotate(Node* x) {
   Node* y = x->right;
   Node* T2 = y->left;

   y->left = x;
   x->right = T2;

   x->height = max(height(x->left), height(x->right)) + 1;
   y->height = max(height(y->left), height(y->right)) + 1;

   return y;
}

Node* AVLTree::rightRotate(Node* y) {
   Node* x = y->left;
   Node* T2 = x->right;

   x->right = y;
   y->left = T2;

   y->height = max(height(y->left), height(y->right)) + 1;
   x->height = max(height(x->left), height(x->right)) + 1;

   return x;
}
