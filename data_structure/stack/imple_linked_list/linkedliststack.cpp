// LinkedListStack.cpp
#include "linkedliststack.h"

LinkedListStack::LinkedListStack() : stackTop(nullptr), stkSize(0) {}

LinkedListStack::~LinkedListStack() {
    freeMemoryLinkedList(stackTop);
}

void LinkedListStack::freeMemoryLinkedList(ListNode *node) {
    while (node != nullptr) {
        ListNode *nextNode = node->next;
        delete node;
        node = nextNode;
    }
}

int LinkedListStack::size() const {
    return stkSize;
}

bool LinkedListStack::isEmpty() const {
    return size() == 0;
}

void LinkedListStack::push(int num) {
    ListNode *node = new ListNode(num);
    node->next = stackTop;
    stackTop = node;
    stkSize++;
}

int LinkedListStack::pop() {
    if (isEmpty())
        throw std::out_of_range("Stack is empty");
    int num = top();
    ListNode *tmp = stackTop;
    stackTop = stackTop->next;
    delete tmp;
    stkSize--;
    return num;
}

int LinkedListStack::top() const {
    if (isEmpty())
        throw std::out_of_range("Stack is empty");
    return stackTop->val;
}

std::vector<int> LinkedListStack::toVector() const {
    ListNode *node = stackTop;
    std::vector<int> res(size());
    for (int i = res.size() - 1; i >= 0; i--) {
        res[i] = node->val;
        node = node->next;
    }
    return res;
}
