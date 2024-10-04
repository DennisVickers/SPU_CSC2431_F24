#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort Algorithm
void BubbleSort(vector<int> &list) {
   
   bool swapped;
   int lastElement;
   int lastUnsorted;

   // Outer loop
   lastElement = (list.size() - 1);
   lastUnsorted = lastElement;
   for (int i = 0; i < lastElement; i++) {
      swapped = false;
      // Inner Loop
      for (int j = 0; j < lastUnsorted; j++) {
         if (list.at(j) > list.at(j + 1)) {
            // Swap elements
            int temp = list.at(j);
            list.at(j) = list.at(j + 1);
            list.at(j + 1) = temp;
            swapped = true;
         }
      }
      // Reduce the search search space
      lastUnsorted--;
      
      // If no two adjacent elements were swapped in inner loop, the listay is sorted
      if (!swapped) {
         break;
      }
   }
}

// Function to print the listay
void printList(const vector<int> &list) {
    for (int num : list) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the bubble sort
int main() {
    vector<int> list = {42, 37, 12, 3, 9};

    cout << "Original list: ";
    printList(list);

    BubbleSort(list);

    cout << "Sorted list: ";
    printList(list);

    return 0;
}
