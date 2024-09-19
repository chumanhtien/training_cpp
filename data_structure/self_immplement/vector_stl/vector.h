#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <memory>  // for std::allocator
#include <stdexcept>  // for std::out_of_range
#include <iterator>  // for iterator traits
#include <algorithm> // for std::swap
#include <cstddef>  // for std::ptrdiff_t

typedef unsigned int uint;

template <typename T>
class MyVector {
private:
    T* data; // pointer to array data
    uint size; // number of elements in vector
    uint capacity; // capacity of vector
    std::allocator<T> allocator; // allocator for type T

public:
    // Nested Iterator class
    class Iterator {
    private:
        T* ptr; // Pointer to the element
    public:
        using iterator_category = std::random_access_iterator_tag;
        using uint = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(T* p = nullptr) : ptr(p) {}

        // Dereference operator
        reference operator*() const { return *ptr; }
        pointer operator->() const { return ptr; }

        // Increment and Decrement operators
        Iterator& operator++() { ++ptr; return *this; }
        Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; }
        Iterator& operator--() { --ptr; return *this; }
        Iterator operator--(int) { Iterator temp = *this; --(*this); return temp; }

        // Arithmetic operators
        Iterator operator+(uint n) const { return Iterator(ptr + n); }
        Iterator operator-(uint n) const { return Iterator(ptr - n); }
        uint operator-(const Iterator& other) const { return ptr - other.ptr; }

        // Compound assignment operators
        Iterator& operator+=(uint n) { ptr += n; return *this; }
        Iterator& operator-=(uint n) { ptr -= n; return *this; }

        // Comparison operators
        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
        bool operator<(const Iterator& other) const { return ptr < other.ptr; }
        bool operator>(const Iterator& other) const { return ptr > other.ptr; }
        bool operator<=(const Iterator& other) const { return ptr <= other.ptr; }
        bool operator>=(const Iterator& other) const { return ptr >= other.ptr; }

        // Indexing operator
        reference operator[](uint n) const { return *(ptr + n); }
    };

    // Constructors
    MyVector();
    MyVector(uint initialSize);
    MyVector(uint initialSize, const T& value);
    MyVector(const MyVector& other); // Copy constructor
    MyVector(MyVector&& other) noexcept; // Move constructor

    // Destructor
    ~MyVector();

    // Assignment operators
    MyVector& operator=(const MyVector& other); // Copy assignment
    MyVector& operator=(MyVector&& other) noexcept; // Move assignment

    // Iterator support
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

    // Reverse Iterators
    std::reverse_iterator<Iterator> rbegin() { return std::reverse_iterator<Iterator>(end()); }
    std::reverse_iterator<Iterator> rend() { return std::reverse_iterator<Iterator>(begin()); }

    // Capacity
    uint getSize() const;
    uint getCapacity() const;
    uint max_size() const;
    bool empty() const;
    void reserve(uint newCapacity);
    void shrink_to_fit();
    void resize(uint newSize);
    void resize(uint newSize, const T& value);

    // Element access
    T& operator[](uint index);
    const T& operator[](uint index) const;
    T& at(uint index);
    const T& at(uint index) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T* dataPtr();
    const T* dataPtr() const;

    // Modifiers
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void assign(uint count, const T& value);
    void clear();
    void swap(MyVector& other);
    template <typename... Args>
    void emplace_back(Args&&... args);
    template <typename... Args>
    void emplace(Iterator position, Args&&... args);
    void insert(Iterator position, const T& value);
    void insert(Iterator position, T&& value);
    Iterator erase(Iterator position);
    Iterator erase(Iterator first, Iterator last);

    // Allocator
    std::allocator<T> get_allocator() const;

private:
    void resize_if_needed();
    void reallocate(uint newCapacity);
};

#include "vector.cpp" // Include the template implementation

#endif
