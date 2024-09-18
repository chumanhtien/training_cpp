#include <iostream>
#include "math_operations.h"

int main() {
    MathOperations mathOps;

    int a = 10, b = 5;
    std::cout << "Add: " << mathOps.add(a, b) << std::endl;
    std::cout << "Subtract: " << mathOps.subtract(a, b) << std::endl;

    return 0;
}
