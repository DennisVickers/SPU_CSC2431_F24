/* 
 * Algorithm to perform a binary search recursively
 * By: Dennis Vickers
 */
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Global constants
const int LIST_SIZE=20;

// Function declarations
int binarySearch(const vector<int> &arr, int lowIdx, int highIdx, int target);
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

   int index = binarySearch(list, 0, list.size() - 1, target);

   if (index != -1) {
      cout << "Element found at index: " << index << endl;
   } else {
      cout << "Element not found" << endl;
   }

   return 0;
}

// Recursive Binary Search Function
int binarySearch(const vector<int> &list, int lowIdx, int highIdx, int target) {
   int midIdx;
   
   // Base case, nothing found
   if (highIdx < lowIdx) return -1;  
		
   //Find a middleish element index
   midIdx = lowIdx + (highIdx - lowIdx) / 2; 

   // Base case, target is present at mid
   if (list.at(midIdx) == target) return midIdx; 

   // If target is greater, ignore lowIdx half
   if (list.at(midIdx) < target) {
      return binarySearch(list, midIdx + 1, highIdx, target);
   }

   // If target is smaller, ignore high half
   return binarySearch(list, lowIdx, midIdx - 1, target);
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
