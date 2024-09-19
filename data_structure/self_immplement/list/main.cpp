#include <iostream>
#include "list.h"
#include "student.h"

int main() {
    MyList<Student> list;

    // Thêm các đối tượng Student vào đầu và cuối danh sách
    list.push_front(Student("Alice", 20, 3.8));
    list.push_back(Student("Bob", 22, 3.6));
    list.push_back(Student("Charlie", 21, 3.9));
    list.push_front(Student("Front", 21, 3.6));

    // Hiển thị kích thước của danh sách
    std::cout << "List size: " << list.size() << std::endl;

    // Hiển thị sinh viên ở đầu và cuối danh sách
    std::cout << "Front student: ";
    list.front().display();
    std::cout << "Back student: ";
    list.back().display();

    // Chèn một sinh viên mới vào giữa danh sách (trước sinh viên thứ hai)
    auto it = list.begin();
    ++it; // Di chuyển đến vị trí thứ hai
    list.insert(it, Student("David", 23, 3.7));

    // Hiển thị lại danh sách sau khi chèn
    std::cout << "\nList after insertion:" << std::endl;
    for (auto it = list.begin(); it != list.end(); ++it) {
        (*it).display();
    }

    // Xóa sinh viên đầu và cuối danh sách
    list.pop_front();
    list.pop_back();

    // Hiển thị danh sách sau khi xóa
    std::cout << "\nList after popping front and back:" << std::endl;
    for (auto it = list.begin(); it != list.end(); ++it) {
        (*it).display();
    }

    // In kích thước cuối cùng của danh sách
    std::cout << "Final list size: " << list.size() << std::endl;

    return 0;
}
