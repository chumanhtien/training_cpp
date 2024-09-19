#ifndef MYLIST_H
#define MYLIST_H

typedef unsigned int uint;

template <typename T>
class MyList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value, Node* prevNode = nullptr, Node* nextNode = nullptr)
            : data(value), prev(prevNode), next(nextNode) {}
    };

    Node* head;
    Node* tail;
    uint listSize;

public:
    // Iterator for the MyList class
    class iterator {
    private:
        Node* current;

    public:
        iterator(Node* ptr = nullptr) : current(ptr) {}

        T& operator*() { return current->data; }
        
        iterator& operator++() {
            current = current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

        bool operator==(const iterator& other) const {
            return current == other.current;
        }

        Node* getNode() const {
            return current;
        }
    };

    MyList(); // Constructor
    ~MyList(); // Destructor

    // Element access
    T& front();
    T& back();

    // Modifiers
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    iterator insert(iterator pos, const T& value);

    // Capacity
    uint size() const;

    // Iterators
    iterator begin();
    iterator end();

private:
    void clear();
};

#include "list.cpp" // apply to complie template

#endif