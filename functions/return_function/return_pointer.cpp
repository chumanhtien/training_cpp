#include<iostream>
using namespace std;

int* findMax(int* a, int* b) {
    return (*a > *b) ? a : b;
}
int* dangerousFunction() {
    int x = 10; // x is local variable
    return &x;  // return address of x
} // x will be deleted here 

int main () {
    int a = 1, b = 2;
    int *c = findMax(&a, &b); // copy value of pointer that ref to a or b is returned
    cout << c << '\n' << *c << '\n';
    *findMax(&a, &b) = 30; // pointer ref to b => change value of b
    cout << "b update: " << b << '\n';
    return 0;
}