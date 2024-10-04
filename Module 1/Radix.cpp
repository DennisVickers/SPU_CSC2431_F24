#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

// Global constants
const int LIST_SIZE=20;
const int VALUE_RANGE=200;

// Declare functions
void radixSort(vector<int> &list, int n, int max);
void printList(const vector<int> &list);
void createList(vector<int> &list, int listSize=5);
int getMax(const vector<int> &list);
int getDigit(int number, int position);

int main() {
    // Create a random list of integers between 1-200
    vector<int> list;
    createList(list, LIST_SIZE);

    cout << "Unsorted list: ";
    printList(list);

    radixSort(list, list.size(), getMax(list));

    cout << "Sorted list: ";
    printList(list);

    return 0;
}

/* Helper functions */

// Function to display a list of integers
void printList(const vector<int> &list) {
    for (int num : list) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to create a random list of integers
void createList(vector<int> &list, int listSize) {
    srand(time(0));
    for (int i=0; i<listSize; i++) {
        list.push_back((rand() % VALUE_RANGE));
    }
}

// Function to get the maximum value in an array
int getMax(const vector<int> &list) {
    int max = list.at(0);
    for (int i = 1; i < list.size(); i++) {
        if (list.at(i) > max) {
            max = list.at(i);
        }
    }
    return max;
}

// Function to isolate and return a single digit from an integer
int getDigit(int number, int position) {
    string retVal="0";  // Set the return value to 0 by default

    string numStr = to_string(number);  // convert the number to a string
    int numSize = to_string(number).length();  // Get the length of the number
    int numIdx = numSize - 1 - position;  // Isolate the digit in the string wanted

    // Return a value if it is pointing to a location, else return 0
    if (numIdx >= 0) {
        retVal = numStr.substr(numIdx,1);
    }

    return stoi(retVal);
}

// Function to sort a list using a Radix algorithm
void radixSort(vector<int> &list, int n, int max) {
    vector<vector <int>> bucket{{},{},{},{},{},{},{},{},{},{}};      //radix of decimal number is 10
    int maxDigits;
    int itemVal;
    int bucketIdx;

    maxDigits = to_string(max).length();

    int count;
    for (int i=0; i<maxDigits; i++) {
        for (int j=0; j<n; j++) {
            itemVal = list.at(j);
            bucketIdx = getDigit(itemVal, i);
            bucket.at(bucketIdx).push_back(itemVal);
        }

        count = 0;
        for(int k = 0; k<10; k++) {
            for (int num : bucket[k]) {
                list.at(count) = num;
                count++;
            }
            bucket.at(k).clear();
        }
    }
}
