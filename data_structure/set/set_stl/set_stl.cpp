#include <iostream>
#include <set>

int main() {
    // Khởi tạo một set với kiểu dữ liệu int
    std::set<int> mySet;

    // 1. Sử dụng insert() để chèn các phần tử
    std::cout << "Chèn phần tử 5 vào set\n";
    mySet.insert(5);

    std::cout << "Chèn phần tử 10 vào set\n";
    mySet.insert(10);

    std::cout << "Chèn phần tử 1 vào set\n";
    mySet.insert(1);

    std::cout << "Chèn phần tử 7 vào set\n";
    mySet.insert(7);

    std::cout << "Chèn phần tử 10 vào set (phần tử đã tồn tại)\n";
    mySet.insert(10);

    // In các phần tử trong set sau khi chèn
    std::cout << "\nCác phần tử trong set sau khi chèn: ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 2. Sử dụng find() để tìm phần tử trong set
    int searchElement = 7;
    std::cout << "\nTìm kiếm phần tử " << searchElement << " trong set.\n";
    auto it = mySet.find(searchElement);
    if (it != mySet.end()) {
        std::cout << "Phần tử " << searchElement << " được tìm thấy trong set.\n";
    } else {
        std::cout << "Phần tử " << searchElement << " không tồn tại trong set.\n";
    }

    // 3. Sử dụng erase() để xóa phần tử khỏi set
    int eraseElement = 5;
    std::cout << "\nXóa phần tử " << eraseElement << " khỏi set.\n";
    mySet.erase(eraseElement);

    // In các phần tử trong set sau khi xóa
    std::cout << "Các phần tử trong set sau khi xóa " << eraseElement << ": ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 4. Sử dụng size() để lấy kích thước của set
    std::cout << "\nSố phần tử trong set hiện tại: " << mySet.size() << "\n";

    // 5. Sử dụng clear() để xóa toàn bộ phần tử trong set
    std::cout << "\nXóa toàn bộ phần tử khỏi set.\n";
    mySet.clear();

    // Kiểm tra set đã rỗng chưa
    if (mySet.empty()) {
        std::cout << "Set hiện tại đã rỗng.\n";
    }

    return 0;
}
