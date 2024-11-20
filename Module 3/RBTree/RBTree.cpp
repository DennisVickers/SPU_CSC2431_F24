#include <iostream>
#include <queue>
#include "RBTree.h"

using namespace std;

// Tree constructor
RBTree::RBTree() : root(nullptr) {}

RBTree::~RBTree() {
   releaseMemory(root);
}

void RBTree::releaseMemory(Node* currNode) {
   if (currNode != nullptr) {
      releaseMemory(currNode->left);
      releaseMemory(currNode->right);
      delete currNode;
   }
}

void RBTree::rotateLeft(Node* onNode) {
   // Step 0: create a copy of the right child
   Node* right_child_tmp = onNode->right;

   // Step 1: Update parent pointers
   onNode->right = right_child_tmp->left;
   if (onNode->right != nullptr) {
      onNode->right->parent = onNode;
   }
   right_child_tmp->parent = onNode->parent;

   // Step 2: Rotate
   if (onNode->parent == nullptr) {
      root = right_child_tmp;
   } else if (onNode == onNode->parent->left) {
      onNode->parent->left = right_child_tmp;
   } else {
      onNode->parent->right = right_child_tmp;
   }

   // Step 4: Finalize the adjustments
   right_child_tmp->left = onNode;
   onNode->parent = right_child_tmp;
}

void RBTree::rotateRight(Node* onNode) {
   // Step 0: create a copy of the right child
   Node* left_child_tmp = onNode->left;

   // Step 1: Update parent pointers
   onNode->left = left_child_tmp->right;
   if (onNode->left) {
      onNode->left->parent = onNode;
   }
   left_child_tmp->parent = onNode->parent;

   // Step 2: Rotate
   if (!onNode->parent) {
      root = left_child_tmp;
   } else if (onNode == onNode->parent->left) {
      onNode->parent->left = left_child_tmp;
   } else {
      onNode->parent->right = left_child_tmp;
   }

   // Step 4: Finalize the adjustments
   left_child_tmp->right = onNode;
   onNode->parent = left_child_tmp;
}

void RBTree::insert(int data) {
   Node* newNode = new Node(data);
   if (root == nullptr) {
      newNode->color = BLACK;
      root = newNode;
   } else {
      Node* temp = root;
      while (temp) {
         if (data < temp->data) {
            if (temp->left == nullptr) {
               temp->left = newNode;
               newNode->parent = temp;
               break;
            } else {
               temp = temp->left;
            }
         } else {
            if (temp->right == nullptr) {
               temp->right = newNode;
               newNode->parent = temp;
               break;
            } else {
               temp = temp->right;
            }
         }
      }
      insertFix(newNode);
   }
}

void RBTree::insertFix(Node* node) {
   Node* parent = nullptr;
   Node* grandparent = nullptr;
   
   while (node != root && node->color != BLACK && node->parent->color == RED) {
      parent = node->parent;
      grandparent = parent->parent;

      if (parent == grandparent->left) {
         Node* uncle = grandparent->right;
         if (uncle && uncle->color == RED) {
            grandparent->color = RED;
            parent->color = BLACK;
            uncle->color = BLACK;
            node = grandparent;
         } else {
            if (node == parent->right) {
               rotateLeft(parent);
               node = parent;
               parent = node->parent;
            }
            rotateRight(grandparent);
            swap(parent->color, grandparent->color);
            node = parent;
         }
      } else {
            Node* uncle = grandparent->left;
            if (uncle && uncle->color == RED) {
               grandparent->color = RED;
               parent->color = BLACK;
               uncle->color = BLACK;
               node = grandparent;
            } else {
               if (node == parent->left) {
                  rotateRight(parent);
                  node = parent;
                  parent = node->parent;
               }
               rotateLeft(grandparent);
               swap(parent->color, grandparent->color);
               node = parent;
            }
      }
   }
   root->color = BLACK;
}

Node* RBTree::findMin(Node *node) {
   Node *ptr = node;
   while (ptr->left) {
      ptr = ptr->left;
   }
   return ptr;
}

Node* RBTree::search(int data) {
   Node* temp = root;
   while (temp) {
      if (data < temp->data) {
         temp = temp->left;
      } else if (data > temp->data) {
         temp = temp->right;
      } else {
         return temp;
      }
   }
   return nullptr;
}

void RBTree::remove(int data) {
   Node* node = search(data);
   if (node == nullptr) return;

   Node* y = nullptr;
   Node* x = nullptr;

   if (node->left == nullptr || node->right == nullptr) {
      y = node;
   } else {
      y = findMin(node->right);
   }

   if (y->left) {
      x = y->left;
   } else {
      x = y->right;
   }

   if (x) {
      x->parent = y->parent;
   }

   if (!y->parent) {
      root = x;
   } else if (y == y->parent->left) {
      y->parent->left = x;
   } else {
      y->parent->right = x;
   }

   if (y != node) {
      node->data = y->data;
   }

   if (y->color == BLACK) {
      deleteFix(x);
   }

   delete y;
}

void RBTree::deleteFix(Node* node) {
   if (!node) {
      return;
   }

   while (node != root && node->color == BLACK) {
      if (node == node->parent->left) {
         Node *sibling = node->parent->right;

         // Case 1: Sibling is red
         if (sibling->color == RED) {
            sibling->color = BLACK;
            node->parent->color = RED;
            rotateLeft(node->parent);
            sibling = node->parent->right;
         }

         // Case 2: Sibling's children are black
         if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
            sibling->color = RED;
            node = node->parent;
         } else {
            // Case 3: Sibling's right child is black
            if (sibling->right->color == BLACK) {
               sibling->left->color = BLACK;
               sibling->color = RED;
               rotateRight(sibling);
               sibling = node->parent->right;
            }

            // Case 4: Sibling's right child is red
            sibling->color = node->parent->color;
            node->parent->color = BLACK;
            sibling->right->color = BLACK;
            rotateLeft(node->parent);
            node = root;
         }
      } else {
         // Symmetric cases for node being the right child
         Node *sibling = node->parent->left;

         // Case 1
         if (sibling->color == RED) {
            sibling->color = BLACK;
            node->parent->color = RED;
            rotateRight(node->parent);
            sibling = node->parent->left;
         }

         // Case 2
         if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
            sibling->color = RED;
            node = node->parent;
         } else {
            // Case 3
            if (sibling->left->color == BLACK) {
               sibling->right->color = BLACK;
               sibling->color = RED;
               rotateLeft(sibling);
               sibling = node->parent->left;
            }

            // Case 4
            sibling->color = node->parent->color;
            node->parent->color = BLACK;
            sibling->left->color = BLACK;
            rotateRight(node->parent);
            node = root;
         }
      }
   }

   node->color = BLACK;
}


void RBTree::inorder() {
   inorderHelper(root);
}

void RBTree::inorderHelper(Node* root) {
   if (root) {
      inorderHelper(root->left);
      cout << root->data;
      cout << ((root->color) ? "B" : "R");
      cout << " ";
      inorderHelper(root->right);
   }
}

void RBTree::levelOrder() {
   levelOrderHelper(root);
}

void RBTree::levelOrderHelper(Node* root) {
   if (root == nullptr) return;

   std::queue<Node*> q;
   q.push(root);

   while (!q.empty()) {
      Node* temp = q.front();
      cout << temp->data;
      cout << ((temp->color) ? "B" : "R");
      cout << " ";
      q.pop();

      if (temp->left != nullptr) q.push(temp->left);
      if (temp->right != nullptr) q.push(temp->right);
   }
}
