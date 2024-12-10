#include "bst.h"
#include <string>
using namespace std;

class AVLTree : public BST {
public:
   void insert(int) override;
   bool search(int);
   bool validate();
   string inOrder();

private:
   bool searchHelper(Node*, int);
   bool validateHelper(Node*);
   void inorderHelper(Node*, string&);
   int height(Node* node);
   int getBalanceFactor(Node*);
   Node* balance(Node*);
   Node* leftRotate(Node*);
   Node* rightRotate(Node*);
};