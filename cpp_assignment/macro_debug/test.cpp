#include <iostream>
using namespace std;

int factorial (int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main () {
    int n;
    cout << "Nhap so nguyen n: "; 
    cin >> n;
    cout << "Fac (" << n << ") = " << factorial(n);
    return 0;
}