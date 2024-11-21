#include "MaxHeap.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
   MaxHeap maxHeap;

   try {
      // Add some elements to the heap
      int itemsInHeap = 10;
      srand(time(nullptr));
      for (int i = 0; i < itemsInHeap; i++) {
         maxHeap.insert(rand()%100);  // Random int between 0 and 99
      }

      cout << "Beginning Heap: ";
      maxHeap.showHeap();

      cout << "Max element: " << maxHeap.extract() << endl;  // Output should be 64
      cout << "Max element after Delete: " << maxHeap.peekMax() << endl;  // Output should be 42

      cout << "Ending Heap: ";
      maxHeap.showHeap();

   } catch (const out_of_range& e) {
      cerr << "Error: " << e.what() << endl;
   }

   return 0;
}
;