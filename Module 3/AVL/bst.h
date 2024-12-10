#pragma once

#include "node.h"

class BST {
public:
   BST() : root(nullptr) {}
   virtual void insert(int);

protected:
   Node* insertHelper(int);
   Node* root;
};
