#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Declare functions
void quickSort(vector<int> &arr, int low, int high);
int partition(vector<int> &arr, int low, int high);
void printList(const vector<int> &list);
void createList(vector<int> &list, int listSize=10);

int main() {
   // Create a random list of integers between 1-100
   vector<int> list;
   createList(list, 7);

   cout << "Original array: ";
   printList(list);

   quickSort(list, 0, list.size() - 1);

   cout << "Sorted array: ";
   printList(list);

   return 0;
}

/* Helper functions */
void printList(const vector<int> &list) {
   for (int num : list) {
       cout << num << " ";
   }
   cout << endl;
}

void createList(vector<int> &list, int listSize) {
   srand(time(0));
   for (int i=0; i<listSize; i++) {
      list.push_back((rand() % 100) + 1);
   }
}


void quickSort(vector<int> &list, int low, int high) {
   int pivotIndex;

   // Base case
   if (low >= high) {
      return;
   }

   // Find the partition
   pivotIndex = partition(list, low, high);

   // Recursively sort the elements before and after partition
   quickSort(list, low, pivotIndex - 1);  // Left list
   quickSort(list, pivotIndex + 1, high); // Right list
}

int partition(vector<int> &list, int low, int high) {
   // Choose the rightmost element as the pivot
   int pivot = list.at(high);
   int temp; // used with swap
  
   // Index for greater element
   int i = low - 1;

   // Traverse through all elements
   for (int j = low; j <= high - 1; j++) {
      // If the current element is smaller than the pivot
      if (list.at(j) < pivot) {
         i++;  // Increment the index of the smaller element
	     temp = list.at(j);
         list.at(j) = list.at(i);
         list.at(i) = temp;
      }
   }
   // Swap the pivot element with the greater element specified by i
   temp = list.at(i+1);
   list.at(i+1) = list.at(high);
   list.at(high) = temp;

   // Return the position from where partition is done
   return (i + 1);
}
