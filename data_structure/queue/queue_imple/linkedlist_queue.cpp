#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Definition for a singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListQueue {
  private:
    ListNode *front, *rear; // Front node front, back node rear
    int queSize;

    // Helper function to free the memory of the linked list
    void freeMemoryLinkedList(ListNode* node) {
        while (node != nullptr) {
            ListNode* temp = node;
            node = node->next;
            delete temp;
        }
    }

  public:
    // Constructor
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        queSize = 0;
    }

    // Destructor
    ~LinkedListQueue() {
        // Traverse the linked list, remove nodes, free memory
        freeMemoryLinkedList(front);
    }

    /* Get the length of the queue */
    int size() {
        return queSize;
    }

    /* Determine if the queue is empty */
    bool isEmpty() {
        return queSize == 0;
    }

    /* Enqueue */
    void push(int num) {
        // Add num behind the tail node
        ListNode *node = new ListNode(num);
        // If the queue is empty, make the head and tail nodes both point to that node
        if (front == nullptr) {
            front = node;
            rear = node;
        }
        // If the queue is not empty, add that node behind the tail node
        else {
            rear->next = node;
            rear = node;
        }
        queSize++;
    }

    /* Dequeue */
    int pop() {
        int num = peek();
        // Remove head node
        ListNode *tmp = front;
        front = front->next;
        // Free memory
        delete tmp;
        queSize--;
        // If the queue becomes empty, set rear to nullptr
        if (queSize == 0) {
            rear = nullptr;
        }
        return num;
    }

    /* Access front element */
    int peek() {
        if (size() == 0)
            throw out_of_range("Queue is empty");
        return front->val;
    }

    /* Convert the linked list to Vector and return */
    vector<int> toVector() {
        ListNode *node = front;
        vector<int> res(size());
        for (int i = 0; i < res.size(); i++) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};

// Example usage
int main() {
    LinkedListQueue queue;
    
    queue.push(10);
    queue.push(20);
    queue.push(30);
    
    cout << "Front element: " << queue.peek() << endl; // Output: 10
    cout << "Queue size: " << queue.size() << endl;    // Output: 3

    queue.pop();
    
    cout << "After one pop, front element: " << queue.peek() << endl; // Output: 20
    cout << "Queue size: " << queue.size() << endl;                  // Output: 2

    vector<int> vec = queue.toVector();
    cout << "Queue contents: ";
    for (int num : vec) {
        cout << num << " ";  // Output: 20 30
    }
    cout << endl;

    return 0;
}
