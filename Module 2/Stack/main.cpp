#include "stack.h"
#include <iostream>
using namespace std;

int main() {
   Stack stack;

   stack.push(10);
   stack.push(20);
   stack.push(30);
   stack.push(40);
   cout << "Top element is " << stack.peek() << endl;

   cout << "Pop!" << endl;
   stack.pop();
   cout << "Top element is " << stack.peek() << endl;

   int find = 20;
   int found = stack.search(find);
   if (found >= 0) {
      cout << "Value " << find << " found at " << found << endl;
   } else {
      cout << "Value " << find << " not found" << endl;
   }

   // Remove all elements
   if (!stack.isEmpty()) {
      cout << "Remove all elements from the stack" << endl;
      while (!stack.isEmpty()) {
         cout << "Pop " << stack.pop() << " ";
      }
      cout << endl;
   }
   if (stack.isEmpty()) {
      cout << "The stack is empty" << endl;
   }

   return 0;
}
