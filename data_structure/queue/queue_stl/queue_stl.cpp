#include <iostream>
#include <queue>

using namespace std;

int main() {
    /* Initialize the queue */
    queue<int> queueSTL;

    /* Enqueue elements */
    queueSTL.push(1);
    queueSTL.push(3);
    queueSTL.push(2);
    queueSTL.push(5);
    queueSTL.push(4);

    /* Print the elements in the queue */
    cout << "Elements in the queue: ";
    queue<int> tempQueue = queueSTL; // Sử dụng một queue tạm để duyệt qua các phần tử mà không làm thay đổi queue chính.
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    /* Access the first element */
    int front = queueSTL.front();
    cout << "Front element: " << front << endl;

    /* Dequeue an element */
    queueSTL.pop();
    cout << "After dequeue, elements in the queue: ";
    tempQueue = queueSTL;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    /* Get the length of the queue */
    int size = queueSTL.size();
    cout << "Size of the queue: " << size << endl;

    /* Check if the queue is empty */
    bool empty = queueSTL.empty();
    cout << "Is the queue empty? " << (empty ? "Yes" : "No") << endl;

    return 0;
}
