#include "MaxHeap.h"

void MaxHeap::insert(int value) {
   heap.push_back(value);     // Add the new value to the end of the bottom of the heap
   heapifyUp(heap.size() - 1);   // Move the new value up the heap starting at the bottom
}

int MaxHeap::extract() {
   if (heap.empty()) {
      throw out_of_range("Heap is empty");
   }

   int result = heap.at(0);   // Keep the root value

   heap.at(0) = heap.back();  // replace the root value with the last value
   heap.pop_back();           // Remove the last element (just moved to root)

   heapifyDown(0);               // Move the root value down the heap

   return result;
}

int MaxHeap::peekMax() const {
   if (heap.empty()) {
      throw out_of_range("Heap is empty");
   }

   return heap.at(0);
}

void MaxHeap::showHeap() const {
   for (int el : heap) {
      std::cout << el << " ";
   }
   std::cout << std::endl;

}

void MaxHeap::heapifyUp(int i) {
   while (i > 0 && heap.at(parent(i)) < heap.at(i)) {
      swap(heap.at(parent(i)), heap.at(i));
      i = parent(i);
   }
}

void MaxHeap::heapifyDown(int i) {
   int maxIndex = i;
   int left = leftChild(i);
   int right = rightChild(i);

   // Compare the left child if there is one
   if (left < heap.size()) {
      if (heap.at(left) > heap.at(maxIndex)) {
         maxIndex = left;  // Go left
      }
   }

   // Compare the right child if there is one
   if (right < heap.size()) {
      if (heap.at(right) > heap.at(maxIndex)) {
         maxIndex = right;  // Go right
      }
   }

   // If the maxIndex is not the current index
   if (i != maxIndex) {
      swap(heap.at(i), heap.at(maxIndex));
      heapifyDown(maxIndex);    // Recursively move down the heap
   }
}
