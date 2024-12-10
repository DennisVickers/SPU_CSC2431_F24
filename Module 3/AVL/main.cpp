#include "avl.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> GetRandomValues(int);

int main() {
   // Create a vector of RandomValues
   vector<int> rValues = GetRandomValues(15);
   // Display vector
   cout << "Original vector:\n";
   for (int rv : rValues) {
     cout << rv << " ";
   }
   cout << endl;

   // Create an empty BST
   AVLTree avlTree;

   // Insert random values into the tree
   for (int val : rValues) {
      avlTree.insert(val);
   }

   // Validate the AVL properties
   cout << "\nValidating AVL properties...\n";
   if (avlTree.validate()) {
      cout << "AVL properties validated successfully. The tree is balanced.\n";
   } else {
      cout << "AVL properties violated. The tree is not balanced.\n";
   }

   // Search for a random value in the AVL tree
   int searchKey = (rand() % rValues.size());
   cout << "\nSearching for " << searchKey << " in the AVL tree...\n";
   if (avlTree.search(searchKey)) {
      cout << "Value " << searchKey << " found in the AVL tree.\n";
   } else {
      cout << "Value " << searchKey << " not found in the AVL tree.\n";
   }

   // Display the inorder traversal of the AVL tree
   cout << "\nInorder traversal of the AVL tree:\n";
   cout << avlTree.inOrder();
   cout << "\n";

   return 0;
}

vector<int> GetRandomValues(int nodesInTree) {
   vector<int> randomValues;
   srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
   for (int i = 0; i < nodesInTree; i++) {
      randomValues.push_back(rand() % 100);
   }
   return randomValues;
}