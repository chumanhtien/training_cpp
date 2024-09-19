#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
void swapByPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    swapByValue(x, y);
    cout << "After swap by value: x = " << x << ", y = " << y << endl;
    swapByPointer(&x, &y);
    cout << "After swap by pointer: x = " << x << ", y = " << y << endl;
    swapByReference(x, y);
    cout << "After swap by reference: x = " << x << ", y = " << y << endl;
    return 0;
}