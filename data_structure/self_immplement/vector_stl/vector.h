#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <initializer_list>

template<typename T>
class Vector {
private:
    T* data;        // Con trỏ trỏ đến mảng động
    int size;       // Số phần tử hiện tại trong vector
    int capacity;   // Sức chứa hiện tại vector

    // Hàm mở rộng sức chứa của mảng động khi cần thiết
    void resizeCapacity(int newCapacity);

public:
    // Constructor khởi tạo vector
    Vector();

    // Constructor với initializer_list
    Vector(std::initializer_list<T> initList);

    // Destructor
    ~Vector();

    // Lớp Iterator nội bộ
    class Iterator {
    private:
        T* ptr;                             // Con trỏ nội bộ của iterator
    public:
        Iterator(T* ptr);

        // Toán tử dereference (*)
        T& operator*();

        // Toán tử tiền tố ++ (tăng vị trí trước)
        Iterator& operator++();

        // Toán tử hậu tố ++ (tăng vị trí sau)
        Iterator operator++(int);

        // Toán tử so sánh ==
        bool operator==(const Iterator& other) const;

        // Toán tử so sánh !=
        bool operator!=(const Iterator& other) const;

        // Toán tử cộng và trừ
        Iterator operator+(int n) const;
        Iterator operator-(int n) const;

        // Getter
        T* getPtr() const;
    };

    // Hàm lấy iterator trỏ đến phần tử đầu tiên
    Iterator begin();

    // Hàm lấy iterator trỏ đến sau phần tử cuối cùng
    Iterator end();

    // Hàm thêm phần tử vào cuối vector
    void push_back(T value);

    // Hàm xóa phần tử ở cuối vector
    void pop_back();

    // Hàm thay đổi kích thước của vector
    void resize(int newSize, T defaultValue = T());

    // Hàm trả về số phần tử hiện tại của vector
    int getSize() const;

    // Hàm trả về phần tử tại vị trí i
    T at(int index);

    // Hàm chèn phần tử vào vị trí bất kỳ bằng iterator
    void insert(Iterator position, T value);

    // Hàm hiển thị các phần tử trong vector
    void display();
};

#include "vector.cpp"

#endif // VECTOR_H
