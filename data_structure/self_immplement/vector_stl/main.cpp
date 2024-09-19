#include <iostream>
#include "vector.h"
#include "Student.h"

int main() {
    // Khởi tạo vector với kiểu Student
    MyVector<Student> students;

    // Thêm các sinh viên vào danh sách
    students.push_back(Student("Alice", 20, 3.8));
    students.push_back(Student("Bob", 22, 3.6));
    students.push_back(Student("Charlie", 21, 3.9));

    // Hiển thị kích thước của vector
    std::cout << "Size: " << students.getSize() << std::endl;

    // Truy cập các sinh viên sử dụng at()
    std::cout << "Student at index 0: ";
    students.at(0).display();

    std::cout << "Student at index 1: ";
    students.at(1).display();

    std::cout << "Student at index 2: ";
    students.at(2).display();

    // Truy cập sinh viên đầu và cuối
    std::cout << "Front student: ";
    students.front().display();

    std::cout << "Back student: ";
    students.back().display();

    // Chèn một sinh viên mới vào vị trí thứ hai
    std::cout<<"vao cho nay: 35\n";
    students.insert(students.begin(), Student("David", 23, 3.7));

    // Hiển thị danh sách sinh viên sau khi chèn
    std::cout << "\nAfter insertion:" << std::endl;
    for (auto it = students.begin(); it != students.end(); ++it) {
        it->display();
    }

    // Xóa sinh viên ở cuối
    students.pop_back();

    // Hiển thị danh sách sinh viên sau khi xóa phần tử cuối
    std::cout << "\nAfter popping back:" << std::endl;
    for (auto it = students.begin(); it != students.end(); ++it) {
        it->display();
    }

    // Kiểm tra vector có rỗng không
    if (!students.empty()) {
        std::cout << "Vector is not empty!" << std::endl;
    }

    // Resize vector, thêm sinh viên với giá trị mặc định
    students.resize(5, Student("Default Student", 18, 4.0));

    std::cout << "\nAfter resizing:" << std::endl;
    for (auto it = students.begin(); it != students.end(); ++it) {
        it->display();
    }

    // Xóa toàn bộ sinh viên
    students.clear();
    std::cout << "Size after clearing: " << students.getSize() << std::endl;

    return 0;
}
