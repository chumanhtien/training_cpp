// ArrayStack.cpp
#include "ArrayStack.h"

ArrayStack::ArrayStack(int initialCapacity)
    : capacity(initialCapacity), topIndex(-1) {
    stackArray = new int[capacity];  // Cấp phát bộ nhớ cho mảng
}

ArrayStack::~ArrayStack() {
    delete[] stackArray;  // Giải phóng bộ nhớ đã cấp phát
}

void ArrayStack::resize(int newCapacity) {
    int* newArray = new int[newCapacity];  // Tạo mảng mới với dung lượng mới

    // Sao chép các phần tử từ mảng cũ sang mảng mới
    for (int i = 0; i <= topIndex; i++) {
        newArray[i] = stackArray[i];
    }

    delete[] stackArray;  // Giải phóng bộ nhớ của mảng cũ
    stackArray = newArray;  // Gán con trỏ mới
    capacity = newCapacity;  // Cập nhật dung lượng mới
}

int ArrayStack::size() const {
    return topIndex + 1;
}

bool ArrayStack::isEmpty() const {
    return topIndex == -1;
}

void ArrayStack::push(int num) {
    if (size() == capacity) {
        resize(capacity * 2);  // Tăng dung lượng mảng nếu cần
    }
    stackArray[++topIndex] = num;
}

int ArrayStack::pop() {
    if (isEmpty())
        throw std::out_of_range("Stack is empty");
    return stackArray[topIndex--];
}

int ArrayStack::top() const {
    if (isEmpty())
        throw std::out_of_range("Stack is empty");
    return stackArray[topIndex];
}
