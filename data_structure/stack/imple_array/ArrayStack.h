// ArrayStack.h
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdexcept>

class ArrayStack {
  private:
    int* stackArray;     // Con trỏ đến mảng chứa các phần tử
    int capacity;        // Dung lượng tối đa của ngăn xếp
    int topIndex;        // Chỉ số của phần tử đỉnh

    void resize(int newCapacity);  // Hàm thay đổi dung lượng của ngăn xếp

  public:
    ArrayStack(int initialCapacity = 10);
    ~ArrayStack();

    // Get the length of the stack
    int size() const;

    // Determine if the stack is empty
    bool isEmpty() const;

    // Push
    void push(int num);

    // Pop
    int pop();

    // Access stack top element
    int top() const;
};

#endif // ARRAYSTACK_H
