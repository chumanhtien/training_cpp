#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main () {
    int a = 100, b = 19;
    cout << add(a, b) << "\n"; // Giá trị copy của giá trị được tính toán sẽ được trả về
    return 0;
}


