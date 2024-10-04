/* 
 * Algorithm to perform a binary search iteratively
 * By: Dennis Vickers
 */
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Global constants
const int LIST_SIZE=20;

// Function declarations
int binarySearch(const vector<int> &list, int target);
void printList(const vector<int> &list);
void createList(vector<int> &list, int listSize=25);

int main() {
   int target;   // Value to search for
	
   // Create a random sorted list of integers
   vector<int> list;
   createList(list, LIST_SIZE);

   // Display the list
   cout << "Random list: ";
   printList(list);

   // randomly select a number between 1 and the highest value in the list
   target = (rand() % list.back()) + 1;  
   cout << "Target: " << target << endl;

   int index = binarySearch(list, target);

   if (index != -1) {
      cout << "Element found at index: " << index << endl;
   } else {
      cout << "Element not found" << endl;
   }

   return 0;
}

// Function to perform an iterative binary search
int binarySearch(const vector<int> &list, int target) {
   int lowIdx = 0;
   int highIdx = list.size() - 1;
   int midIdx;

   while (lowIdx <= highIdx) {
      midIdx = lowIdx + (highIdx - lowIdx) / 2;

      if (list.at(midIdx) == target) {
         return midIdx; // Element found
      } else if (list.at(midIdx) < target) {
         lowIdx = midIdx + 1; // Search in the right half
      } else {
         highIdx = midIdx - 1; // Search in the left half
      }
   }

   return -1; // Element not found
}

/* Helper functions */

// Function to display a list of integers
void printList(const vector<int> &list) {
   for (int i=0; i<list.size(); i++) {
      cout << i << ":" << list.at(i) << " ";
   }
   cout << endl;
}

// Function to create a random list of integers
void createList(vector<int> &list, int listSize) {
   int newValue = 0;
   int increment = 0;
	
   srand(time(0));
   for (int i=0; i<listSize; i++) {
      increment = (rand() % 3) + 1;
	  newValue += increment;
      list.push_back(newValue);
   }
}
