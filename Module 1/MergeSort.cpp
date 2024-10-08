#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Function declarations
void createList(vector<int>&, int s=10);
void printList(const vector<int>&);
void merge(vector<int>&, int, int, int);
void mergeSort(vector<int>&, int, int);

int main() {
   
  // Create a random list of integers between 1-100
  vector<int> list;
  createList(list);

  cout << "Unsorted list: ";
  printList(list);

  mergeSort(list, 0, list.size() - 1);

  cout << "Sorted list: ";
  printList(list);

  return 0;
}

// Helper functions

void printList(const vector<int> &list) {
  for (int el : list) {
    cout << el << " ";
  }
  cout << endl;
}

void createList(vector<int> &list, int listSize) {
  srand(time(nullptr));
  for (int i=0; i<listSize; i++) {
    list.push_back((rand() % 100) + 1);
  }
}

// Merge Sort function
void mergeSort(vector<int> &list, int left, int right) {

  // Base case, when the sublist is down to one element
  if (left >= right) return;

  // Find the middle of the list
  int mid = left + ((right - left) / 2);
	
  // Split the list into sublists and sort them
  mergeSort(list, left, mid);
  mergeSort(list, mid + 1, right);

  // Merge the lists of one back together
  merge(list, left, mid, right);
}

// Function to merge two sorted lists
void merge(vector<int> &list, int left, int mid, int right) {
  // Initialize temporary lists to hold the values of the left and right sub-lists
  vector<int> leftList(mid - left + 1);
  vector<int> rightList(right - mid);

  // Copy the elements to the temporary lists
  for (int i = 0; i < leftList.size(); i++) {
    leftList.at(i) = list.at(left + i);
  }
  for (int j = 0; j < rightList.size(); j++) {
    rightList.at(j) = list.at(mid + 1 + j);
  }

  // Merge the temporary lists back into the original list
  int i = 0, j = 0, k = left;
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
