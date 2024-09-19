#include<iostream>
using namespace std;

void swapValue (int &value1, int &value2) {
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

// khai bao con tro ham
void (*pSwap) (int &, int &);

int main() {
    
    pSwap = swapValue;
    int a = 1, b = 10;
    cout << "a, b: " << a << ", " << b << '\n';
    (*pSwap) (a, b);
    cout << "a, b after:  " << a << ", " << b << '\n';

    return 0;
}