#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
   BinaryTree tree;

   // Insert nodes
   tree.insert(10);
   tree.insert(5);
   tree.insert(15);
   tree.insert(2);
   tree.insert(7);
   tree.insert(12);
   tree.insert(18);

   // Perform traversals
   cout << "In-Order Traversal: ";
   tree.inOrderTraversal(tree.root);
   cout << endl;

   cout << "Pre-Order Traversal: ";
   tree.preOrderTraversal(tree.root);
   cout << endl;

   cout << "Post-Order Traversal: ";
   tree.postOrderTraversal(tree.root);
   cout << endl;
   return 0;
}
