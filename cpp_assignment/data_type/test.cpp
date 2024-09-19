#include <iostream>
using namespace std;

int main () {
    short int x;
    short y;
    cout << sizeof(x) << sizeof (y) << '\n';
    int a = 6; double b = 6.0;
    bool res = (a == b);
    cout << "Result: " << res;
    return 0;
}