#ifndef MYVECTOR_CPP
#define MYVECTOR_CPP
#include "vector.h"

// Constructor khởi tạo vector
template<typename T>
Vector<T>::Vector() {
    capacity = 1;                       
    size = 0;                           
    data = new T[capacity];             
}

// Constructor với initializer_list
template<typename T>
Vector<T>::Vector(std::initializer_list<T> initList) {
    size = initList.size();
    capacity = size;                    
    data = new T[capacity];
    int index = 0;
    for (const T& value : initList) {
        data[index++] = value;          
    }
}

// Destructor
template<typename T>
Vector<T>::~Vector() {
    delete[] data;                      
}

// Hàm mở rộng sức chứa
template<typename T>
void Vector<T>::resizeCapacity(int newCapacity) {
    T* newData = new T[newCapacity];    
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];           
    }
    delete[] data;                      
    data = newData;                     
    capacity = newCapacity;             
}

// Lớp Iterator nội bộ
template<typename T>
Vector<T>::Iterator::Iterator(T* ptr) : ptr(ptr) {}

template<typename T>
T& Vector<T>::Iterator::operator*() { return *ptr; }

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
    ptr++;
    return *this;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ptr++;
    return temp;
}

template<typename T>
bool Vector<T>::Iterator::operator==(const Iterator& other) const {
    return ptr == other.ptr;
}

template<typename T>
bool Vector<T>::Iterator::operator!=(const Iterator& other) const {
    return ptr != other.ptr;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator+(int n) const {
    return Iterator(ptr + n);
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator-(int n) const {
    return Iterator(ptr - n);
}

template<typename T>
T* Vector<T>::Iterator::getPtr() const {
    return ptr;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::begin() {
    return Iterator(data);              
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::end() {
    return Iterator(data + size);       
}

template<typename T>
void Vector<T>::push_back(T value) {
    if (size == capacity) {
        resizeCapacity(2 * capacity);    
    }
    data[size++] = value;               
}

template<typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        size--;                         
    } else {
        std::cout << "Vector rỗng, không có phần tử để xóa." << std::endl;
    }
}

template<typename T>
void Vector<T>::resize(int newSize, T defaultValue) {
    if (newSize > size) {
        if (newSize > capacity) {
            resizeCapacity(2 * capacity); 
        }
        for (int i = size; i < newSize; i++) {
            data[i] = defaultValue;       
        }
    }
    size = newSize;                     
}

template<typename T>
int Vector<T>::getSize() const {
    return size;
}

template<typename T>
T Vector<T>::at(int index) {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cerr << "Index không hợp lệ!" << std::endl;
        return T();
    }
}

template<typename T>
void Vector<T>::insert(Iterator position, T value) {
    int index = position.getPtr() - data;
    if (index < 0 || index >= size) {
        std::cout << "Không tồn tại vị trí " << index << std::endl;
        return;
    }
    if (size == capacity) {
        resizeCapacity(2 * capacity);
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}
    
template<typename T>
void Vector<T>::display() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
#endif