#include <iostream>

// Tail-recursive helper function with an accumulator
int factorial_helper(int n, int accumulator) {
    if (n == 0 || n == 1)
        return accumulator;  // Base case: return the accumulated result
    else
        return factorial_helper(n - 1, n * accumulator);  // Recursive call with updated accumulator
}

// Tail-recursive factorial function
int factorial(int n) {
    return factorial_helper(n, 1);  // Start with an accumulator of 1
}

int main() {
    std::cout << "Factorial of 5 is " << factorial(5) << std::endl;
    return 0;
}
