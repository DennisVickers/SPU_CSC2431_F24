#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &list);
void printList(const vector<int> &list);

int main() {
  vector<int> list = {42,37,12,3,9};

  cout << "Unsorted list: ";
  printList(list);

  BubbleSort(list);

  cout << "Sorted list: ";
  printList(list);

  return 0;
}

void printList(const vector<int> &list) {
  for (int num : list) {
    cout << num << " ";
  }
  cout << endl;
}

void BubbleSort(vector<int> &list) {
  bool swapped;
  int lastElement;
  int lastUnsorted;

  // Outer loop
  lastElement = (list.size() - 1);
  lastUnsorted = lastElement;
  for (int i=0; i < lastElement; i++) {
    swapped = false;
    // inner loop
    for (int j=0; j< lastUnsorted; j++) {
      if (list.at(j) > list.at(j + 1)) {
        // swap elements
        int temp = list.at(j);
        list.at(j) = list.at(j+1);
        list.at(j+1) = temp;
        swapped = true;
      }
    }
    // reduce the search space
    lastUnsorted--;

    // if no two adjacent elements were swapped in the
    // inner loop the list is sorted
    if (!swapped) {
      break;
    }
  }
}
