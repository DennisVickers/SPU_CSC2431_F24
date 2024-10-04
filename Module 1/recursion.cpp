//
// Recursion
//
#include <iostream>
using namespace std;

void direct(int n);
void indirectA(int n);
void indirectB(int n);

int main() {
    int n = 5;
    cout << "Starting recursion with n = " << n << endl;

    // Direct recursion
    direct(n);

    // Indirect recursion
    // indirectA(n);

    return 0;
}

void direct(int n) {
  if (n <= 0) return;   // Base case

  cout << "In direct: " << n << endl;
  direct(n - 1);  
}

void indirectA(int n) {
  if (n <= 0) return; // Base condition
  
  cout << "In indirectA: " << n << endl;
  indirectB(n);
}

void indirectB(int n) {
  cout << "In indirectB: " << n << endl;
  indirectA(n - 1);
}

  