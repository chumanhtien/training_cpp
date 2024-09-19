// main.cpp
#include <iostream>
#include "linkedliststack.h"

int main() {
    LinkedListStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl;  // Should print 30
    std::cout << "Stack size: " << stack.size() << std::endl;  // Should print 3

    std::vector<int> stackContents = stack.toVector();
    std::cout << "Stack contents: ";
    for (int value : stackContents) {
        std::cout << value << " ";
    }
    std::cout << std::endl;  // Should print 30 20 10

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;  // Should print 20
    std::cout << "Stack size after pop: " << stack.size() << std::endl;  // Should print 2

    return 0;
}
