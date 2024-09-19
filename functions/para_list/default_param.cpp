#include <iostream>
using namespace std;

// Prototype của hàm với giá trị tham số mặc định
void printInfo(const string &name, int age = 30, const string &city = "Hanoi");

int main() {
    // Gọi hàm với đầy đủ các tham số
    printInfo("Alice", 25, "New York");

    // Gọi hàm bỏ qua tham số cuối cùng (city)
    printInfo("Bob", 40);

    // Gọi hàm bỏ qua cả hai tham số mặc định (age và city)
    printInfo("Charlie");

    return 0;
}

// Định nghĩa hàm không lặp lại giá trị mặc định
void printInfo(const string &name, int age, const string &city) {
    cout << "Name: " << name << ", Age: " << age << ", City: " << city << endl;
}
