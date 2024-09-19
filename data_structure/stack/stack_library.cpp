#include<iostream>
#include<stack>
using namespace std;
int main() {

    /* Initialize the stack */
    stack<int> s;

    /* Push elements onto the stack */
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(4);

    stack<int> tempStack = s;
    // In các phần tử của tempStack
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
        cout << "size: " << tempStack.size() << " ";
    }
    cout << '\n';
    /* Access the top element of the stack */
    int top = s.top();
    cout << "top: " << top << '\n';

    /* Pop an element from the stack */
    s.pop(); // No return value

    /* Get the length of the stack */
    int size = s.size();
    cout << "size: " << size << '\n';

    /* Check if the stack is empty */
    bool empty = s.empty();
    cout << "empty: " << empty << '\n'; 
    
    return 0;
}