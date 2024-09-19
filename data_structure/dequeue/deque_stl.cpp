#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;

    // Thêm phần tử vào đầu và cuối
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);

    std::cout << "Các phần tử trong deque: ";
    for (int n : dq) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // Truy cập và thao tác với phần tử
    std::cout << "Phần tử ở vị trí đầu tiên: " << dq.front() << "\n";
    std::cout << "Phần tử ở vị trí cuối cùng: " << dq.back() << "\n";

    // Xóa phần tử
    dq.pop_front();
    dq.pop_back();

    std::cout << "Các phần tử trong deque sau khi xóa: ";
    for (int n : dq) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}
