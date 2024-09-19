// LinkedListStack.h
#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include "listnode.h"
#include <vector>
#include <stdexcept>

class LinkedListStack {
  private:
    ListNode *stackTop; // Use the head node as the top of the stack
    int stkSize;        // Length of the stack

    // Helper function to free memory
    void freeMemoryLinkedList(ListNode *node);

  public:
    LinkedListStack();
    ~LinkedListStack();

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

    // Convert the List to Array and return
    std::vector<int> toVector() const;
};

#endif // LINKEDLISTSTACK_H
