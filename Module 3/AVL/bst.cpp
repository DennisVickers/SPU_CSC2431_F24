#include "bst.h"
#include <iostream>

void BST::insert(int newData) {
   Node* newNode = insertHelper(newData);
}

Node* BST::insertHelper(int newData) {
   Node* newNode = new Node(newData);

   // Check to see if the tree is empty, if so, create the root
   if (root == nullptr) {
      root = newNode;
      return newNode;
   }

   Node *current = root;
   Node *parent = nullptr;

   // Find the correct leaf
   while (current != nullptr) {
      parent = current;
      if (newData < current->data) {
         current = current->left;
      } else {
         current = current->right;
      }
   }
   
   // Create a new leaf on the left or right
   if (newData < parent->data) {
      parent->left = new Node(newData);
   } else {
      parent->right = new Node(newData);
   }

   return newNode;
}
