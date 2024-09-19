#ifndef MYLIST_CPP
#define MYLIST_CPP

#include "list.h"
#include <stdexcept>

template <typename T>
MyList<T>::MyList() : head(nullptr), tail(nullptr), listSize(0) {}

template <typename T>
MyList<T>::~MyList() {
    clear();
}

template <typename T>
void MyList<T>::push_front(const T& value) {
    Node* newNode = new Node(value, nullptr, head);
    if (head != nullptr) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
    ++listSize;
}

template <typename T>
void MyList<T>::push_back(const T& value) {
    Node* newNode = new Node(value, tail, nullptr);
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode; // nếu danh sách rỗng
    }
    tail = newNode;
    ++listSize;
}

template <typename T>
void MyList<T>::pop_front() {
    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    }
    Node* oldHead = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete oldHead;
    --listSize;
}

template <typename T>
void MyList<T>::pop_back() {
    if (tail == nullptr) {
        throw std::out_of_range("List is empty");
    }
    Node* oldTail = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete oldTail;
    --listSize;
}


template <typename T>
T& MyList<T>::front() {
    if(head == nullptr) {
        throw std::out_of_range("List is empty");
    }
    return head->data;
}

template <typename T>
T& MyList<T>::back() {
    if (tail == nullptr) {
        throw std::out_of_range("List is empty");
    }
    return tail->data;
}

template <typename T>
uint MyList<T>::size() const {
    return listSize;
}

template <typename T>
typename MyList<T>::iterator MyList<T>::begin() {
    return iterator(head);
}

template <typename T>
typename MyList<T>::iterator MyList<T>::end() {
    return iterator(nullptr);
}

template <typename T>
typename MyList<T>::iterator MyList<T>::insert(iterator pos, const T& value) {
    Node* current = pos.getNode();
    Node* newNode = new Node(value);

    if (current) {
        newNode->next = current;
        newNode->prev = current->prev;

        if (current->prev) {
            current->prev->next = newNode;
        } else {
            head = newNode;
        }
        current->prev = newNode;
    } else {
        push_back(value);
        return iterator(tail);
    }

    if (newNode->prev == nullptr) {
        head = newNode;
    }

    ++listSize;
    return iterator(newNode);
}

template <typename T>
void MyList<T>::clear() {
    while(head != nullptr) {
        pop_front();
    }
}

#endif // MYLIST_CPP