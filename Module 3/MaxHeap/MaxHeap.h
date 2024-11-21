#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
using namespace std;

class MaxHeap {
public:
   void insert(int);       // Add an element on the heap
   int extract();          // Remove and return the maximum element
   int peekMax() const;    // Return the maximum element without removing it
   void showHeap() const;  // Show the heap as a string

private:
   vector<int> heap;

   // Helper functions
   int parent(int i) { return (i - 1) / 2; };      // Get parent index
   int leftChild(int i) { return (2 * i) + 1; };   // Get left child index
   int rightChild(int i) { return (2 * i) + 2; };  // Get right child index
   void heapifyUp(int i);                          // Percolate an index up the heap
   void heapifyDown(int i);                        // Move an index down the heap
};
