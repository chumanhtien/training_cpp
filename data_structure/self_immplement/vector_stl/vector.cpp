// vector_impl.h
#ifndef MYVECTOR_IMPL_H
#define MYVECTOR_IMPL_H

#include "vector.h"
#include <iostream>

// Constructors
template <typename T>
MyVector<T>::MyVector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
MyVector<T>::MyVector(uint initialSize) : size(initialSize), capacity(initialSize) {
    data = allocator.allocate(capacity);
    for (uint i = 0; i < size; ++i) {
        allocator.construct(&data[i], T());
    }
}

template <typename T>
MyVector<T>::MyVector(uint initialSize, const T& value) : size(initialSize), capacity(initialSize) {
    data = allocator.allocate(capacity);
    for (uint i = 0; i < size; ++i) {
        allocator.construct(&data[i], value);
    }
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) : size(other.size), capacity(other.capacity) {
    data = allocator.allocate(capacity);
    for (uint i = 0; i < size; ++i) {
        allocator.construct(&data[i], other.data[i]);
    }
}

template <typename T>
MyVector<T>::MyVector(MyVector&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

// Destructor
template <typename T>
MyVector<T>::~MyVector() {
    clear();
    allocator.deallocate(data, capacity);
}

// Assignment operators
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this != &other) {
        clear();
        allocator.deallocate(data, capacity);
        size = other.size;
        capacity = other.capacity;
        data = allocator.allocate(capacity);
        for (uint i = 0; i < size; ++i) {
            allocator.construct(&data[i], other.data[i]);
        }
    }
    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept {
    if (this != &other) {
        clear();
        allocator.deallocate(data, capacity);
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

// Capacity
template <typename T>
uint MyVector<T>::getSize() const {
    return size;
}

template <typename T>
uint MyVector<T>::getCapacity() const {
    return capacity;
}

template <typename T>
uint MyVector<T>::max_size() const {
    return std::allocator_traits<std::allocator<T>>::max_size(allocator);
}

template <typename T>
bool MyVector<T>::empty() const {
    return size == 0;
}

template <typename T>
void MyVector<T>::reserve(uint newCapacity) {
    if (newCapacity > capacity) {
        reallocate(newCapacity);
    }
}

template <typename T>
void MyVector<T>::shrink_to_fit() {
    if (size < capacity) {
        reallocate(size);
    }
}

template <typename T>
void MyVector<T>::resize(uint newSize) {
    resize(newSize, T());
}

template <typename T>
void MyVector<T>::resize(uint newSize, const T& value) {
    if (newSize > size) {
        reserve(newSize);
        for (uint i = size; i < newSize; ++i) {
            allocator.construct(&data[i], value);
        }
    } else {
        for (uint i = newSize; i < size; ++i) {
            allocator.destroy(&data[i]);
        }
    }
    size = newSize;
}

// Element access
template <typename T>
T& MyVector<T>::operator[](uint index) {
    return data[index];
}

template <typename T>
const T& MyVector<T>::operator[](uint index) const {
    return data[index];
}

template <typename T>
T& MyVector<T>::at(uint index) {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
const T& MyVector<T>::at(uint index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
T& MyVector<T>::front() {
    return data[0];
}

template <typename T>
const T& MyVector<T>::front() const {
    return data[0];
}

template <typename T>
T& MyVector<T>::back() {
    return data[size - 1];
}

template <typename T>
const T& MyVector<T>::back() const {
    return data[size - 1];
}

template <typename T>
T* MyVector<T>::dataPtr() {
    return data;
}

template <typename T>
const T* MyVector<T>::dataPtr() const {
    return data;
}

// Modifiers
template <typename T>
void MyVector<T>::push_back(const T& value) {
    resize_if_needed();
    allocator.construct(&data[size], value);
    ++size;
}

template <typename T>
void MyVector<T>::push_back(T&& value) {
    resize_if_needed();
    allocator.construct(&data[size], std::move(value));
    ++size;
}

template <typename T>
void MyVector<T>::pop_back() {
    if (size > 0) {
        allocator.destroy(&data[size - 1]);
        --size;
    }
}

template <typename T>
void MyVector<T>::clear() {
    for (uint i = 0; i < size; ++i) {
        allocator.destroy(&data[i]);
    }
    size = 0;
}

template <typename T>
void MyVector<T>::swap(MyVector& other) {
    std::swap(data, other.data);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}

template <typename T>
template <typename... Args>
void MyVector<T>::emplace_back(Args&&... args) {
    resize_if_needed();
    allocator.construct(&data[size], std::forward<Args>(args)...);
    ++size;
}

template <typename T>
template <typename... Args>
void MyVector<T>::emplace(Iterator position, Args&&... args) {
    uint index = position - begin();
    if (size >= capacity) {
        reallocate(capacity == 0 ? 1 : capacity * 2);
    }
    for (uint i = size; i > index; --i) {
        data[i] = std::move(data[i - 1]);
    }
    allocator.construct(&data[index], std::forward<Args>(args)...);
    ++size;
}

template <typename T>
void MyVector<T>::insert(Iterator position, const T& value) {
    uint index = position - begin();
    if (size >= capacity) {
        reallocate(capacity == 0 ? 1 : capacity * 2);
    }
    for (uint i = size; i > index; --i) {
        data[i] = std::move(data[i - 1]);
    }
    allocator.construct(&data[index], value);
    ++size;
    // return;
}

template <typename T>
void MyVector<T>::insert(Iterator position, T&& value) {
    uint index = position - begin();
    std::cout<<"index: "<<index<<'\n';

    if (size >= capacity) {
        reallocate(capacity == 0 ? 1 : capacity * 2);
    }
    for (uint i = size; i > index; --i) {
        data[i] = std::move(data[i - 1]);
    }
    allocator.construct(&data[index], std::move(value));
    ++size;
    // return Iterator(data + index);
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::erase(Iterator position) {
    uint index = position - begin();
    allocator.destroy(&data[index]);
    for (uint i = index; i < size - 1; ++i) {
        data[i] = std::move(data[i + 1]);
    }
    --size;
    return Iterator(data + index);
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::erase(Iterator first, Iterator last) {
    uint firstIndex = first - begin();
    uint lastIndex = last - begin();
    for (uint i = firstIndex; i < lastIndex; ++i) {
        allocator.destroy(&data[i]);
    }
    for (uint i = lastIndex; i < size; ++i) {
        data[firstIndex + (i - lastIndex)] = std::move(data[i]);
    }
    size -= (lastIndex - firstIndex);
    return Iterator(data + firstIndex);
}

// Allocator
template <typename T>
std::allocator<T> MyVector<T>::get_allocator() const {
    return allocator;
}

// Private helper functions
template <typename T>
void MyVector<T>::resize_if_needed() {
    if (size >= capacity) {
        reallocate(capacity == 0 ? 1 : capacity * 2);
    }
}

template <typename T>
void MyVector<T>::reallocate(uint newCapacity) {
    T* newData = allocator.allocate(newCapacity);
    for (uint i = 0; i < size; ++i) {
        allocator.construct(&newData[i], std::move(data[i]));
        allocator.destroy(&data[i]);
    }
    allocator.deallocate(data, capacity);
    data = newData;
    capacity = newCapacity;
}

#endif
