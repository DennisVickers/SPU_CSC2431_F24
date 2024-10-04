//
// Pointers
//
#include <iostream>
using namespace std;

int main() {

  /* Basic Syntax */
  int x = 10;
  int* p;       // Declare an integer pointer
  p = &x;       // Assign the address of x to p
  cout << "x=" << *p << endl;   // Dereference pointer

  /* Reassignment */
  int y = 20;
  p = &y;
  cout << "y=" << *p << endl;   // Dereference pointer

  /* Pointer arithmetic */
  int arr[5] = {5, 4, 3, 2, 1};
  p = arr;    // p points to the first element of the array
  cout << "arr[0]=" << *p << endl;   // Dereference pointer
  p++;        // p now points to the second element
  cout << "arr[1]=" << *p << endl;   // Dereference pointer

  /* Pointers to Pointers */
  *p = 15;
  int** pP = &p;   // pp is a pointer to a pointer to an int
  cout << "pP=" << **pP << endl;

  /* Dynamic Memory Allocation */
  int* pD = new int;  // Allocates an integer in the heap and returns its address
  *pD = 30;           // Assigns 10 to the allocated integer
  cout << "pD=" << *pD << endl;
  delete pD;          // Deallocates the memory

  return 0;
}