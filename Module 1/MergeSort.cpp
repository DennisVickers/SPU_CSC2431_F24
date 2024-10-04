#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Function declarations
void createList(vector<int> &list, int listSize=10);
void printList(const vector<int> &list);
void merge(vector<int> &list, int lowIdx, int middleIdx, int highIdx);
void mergeSort(vector<int> &list, int lowIdx, int highIdx);

int main() {
   
   // Create a random list of integers between 1-100
   vector<int> list;
   createList(list, 5);

   cout << "Unsorted list: ";
   printList(list);

   mergeSort(list, 0, list.size() - 1);

   cout << "Sorted list: ";
   printList(list);

   return 0;
}

// Helper functions

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

// Merge Sort function
void mergeSort(vector<int> &list, int lowIdx, int highIdx) {
   int middleIdx;

   // Base case
   if (lowIdx >= highIdx) {
      return;
   }

   // Find the middleIdx of the list
   middleIdx = lowIdx + ((highIdx - lowIdx) / 2);
	
   // Split the list
   mergeSort(list, lowIdx, middleIdx);
   mergeSort(list, middleIdx + 1, highIdx);

   // Merge the lists of one back together
   merge(list, lowIdx, middleIdx, highIdx);
}

// Function to merge two sorted lists
void merge(vector<int> &list, int lowIdx, int middleIdx, int highIdx) {
   // Initialize temporary lists to hold the values of the left and right sub-lists
   vector<int> leftList(middleIdx - lowIdx + 1);
   vector<int> rightList(highIdx - middleIdx);

   // Copy the elements to the temporary lists
   for (int i = 0; i < leftList.size(); i++) {
      leftList.at(i) = list.at(lowIdx + i);
   }
   for (int j = 0; j < rightList.size(); j++) {
      rightList.at(j) = list.at(middleIdx + 1 + j);
   }

   // Merge the temporary lists back into the original list
   int i = 0, j = 0, k = lowIdx;
   while (i < leftList.size() && j < rightList.size()) {
      if (leftList.at(i) <= rightList.at(j)) {
         list.at(k) = leftList.at(i);
         i++;
      } else {
         list.at(k) = rightList.at(j);
         j++;
      }
      k++;
   }

   // Copy any remaining elements from leftList, if there are any
   while (i < leftList.size()) {
      list.at(k) = leftList.at(i);
      i++;
      k++;
   }

   // Copy any remaining elements from rightList, if there are any
   while (j < rightList.size()) {
      list.at(k) = rightList.at(j);
      j++;
      k++;
   }
}
