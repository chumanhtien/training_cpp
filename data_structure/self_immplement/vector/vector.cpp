#ifndef MYVECTOR_CPP
#define MYVECTOR_CPP

#include <stdexcept>  // for std::out_of_range
#include "vector.h"

template <typename T>
MyVector<T>::MyVector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
MyVector<T>::~MyVector() {
    allocator.deallocate(data, capacity);
}

template <typename T>
T& MyVector<T>::operator[](uint index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
    if (size == capacity) {
        resize();
    }
    data[size] = value;
    size++;
}

template <typename T>
void MyVector<T>::pop_back() {
    if (size > 0) {
        --size;
    } else {
        throw std::out_of_range("Vector is empty");
    }
}

template <typename T>
uint MyVector<T>::getSize() const {
    return size;
}

template <typename T>
uint MyVector<T>::getCapacity() const {
    return capacity;
}

template <typename T>
void MyVector<T>::resize() {
    uint newCapacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = allocator.allocate(newCapacity);

    for (uint i = 0; i < size; ++i) {
        allocator.construct(&newData[i], data[i]);
        allocator.destroy(&data[i]);
    }

    allocator.deallocate(data, capacity);
    data = newData;
    capacity = newCapacity;
}

#endif
