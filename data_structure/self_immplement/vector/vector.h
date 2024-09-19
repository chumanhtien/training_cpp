#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <memory> // for std::allocator

typedef unsigned int uint;

template <typename T>

class MyVector {
private: 
    T* data; // pointer to array data
    uint size; // number of element in vector
    uint capacity; // capacity of vector
    std::allocator<T> allocator; // allocator for type T

public:
    MyVector(); // constructor
    ~MyVector(); // destructor

    T& operator[](uint index); // get item with index

    void push_back(const T& value); // insert item to end
    void pop_back(); // delete last item
    uint getSize() const; // get size of vector
    uint getCapacity() const; // get capacity of vector

private:
    void resize(); // more allocate memory for vector
};

#include "vector.cpp" // Include để template hoạt động đúng

#endif