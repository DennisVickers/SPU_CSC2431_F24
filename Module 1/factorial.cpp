#include <iostream>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);  // The recursive call is not the last operation.
}

int main() {
    std::cout << "Factorial of 5 is " << factorial(5) << std::endl;
    return 0;
}
