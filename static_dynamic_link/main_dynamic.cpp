#include<iostream>
using namespace std;

// Khai báo hàm từ thư viện: tĩnh động như nhau
int add(int a, int b);
int multiply(int a, int b);

int main() {
    int res1 = add(5, 10);
    int res2 = multiply(5, 10);
    cout << "Add: " << res1 << endl;
    cout << "Multi: " << res2 << endl;
    return 0;
}