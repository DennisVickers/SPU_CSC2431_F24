#include "RBTree.h"
#include <iostream>
using namespace std;

void showTree(RBTree* tree) {
   cout << "Level order: ";
   tree->levelOrder();
   cout << endl;
   cout << "In order: ";
   tree->inorder();
   cout << endl;
}

int main() {
   RBTree tree;

   // Build a balanced tree
   // Insert 5,2,11,8,12,6,9
   tree.insert(5);
   tree.insert(2);
   tree.insert(11);
   tree.insert(8);
   tree.insert(12);
   tree.insert(6);
   tree.insert(9);

   cout << "Balanced Red-Black Tree" << endl;
   showTree(&tree);

   // Unbalance tree and re-balance it
   tree.insert(10);
   cout << endl << "After Insert (10)" << endl;
   showTree(&tree);

   // Remove a node from the tree and re-balance it
   tree.remove(12);
   cout << endl << "After Remove (12)" << endl;
   showTree(&tree);

   return 0;
}
