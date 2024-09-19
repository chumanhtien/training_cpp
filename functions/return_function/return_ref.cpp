#include<iostream>
using namespace std;

int& findMax(int& a, int& b) {
    return (a > b) ? a : b;
}

int& dangerousFunc() {
    int x = 10;
    return &x; // 
} // vùng nhớ của x bị giải phóng => error complie

int main() {
    int x = 5;
    int y = 10;
    int& max = findMax(x, y); // &max là tham chiếu tới y, max là y luôn 
    cout << "max: " << max << '\n';
    max = 20; // Thay đổi giá trị của y
    cout << "y: " << y << '\n';

}
