#include "vector.h"
#include "Student.h"
#include <iostream>

// Định nghĩa class Student

int main() {
    // Khởi tạo Vector chứa các đối tượng Student
    Vector<Student> students;

    students.push_back(Student("Alice", 20, 2.8));
    students.push_back(Student("Bob", 22, 3.2));
    students.push_back(Student("Charlie", 21, 3.44));
    students.pop_back();


    // Sử dụng iterator để duyệt qua các sinh viên
    std::cout << "Duyệt qua danh sách sinh viên bằng iterator:" << std::endl;
    for (Vector<Student>::Iterator it = students.begin(); it != students.end(); ++it) {
        (*it).display();
    }

    // Thêm một sinh viên vào vị trí đầu tiên
    students.insert(students.begin() + 1, Student("Dave", 23, 2.33));
    std::cout << "Sau khi chèn Dave vào đầu danh sách:" << std::endl;
    // students.display();
    for (Vector<Student>::Iterator it = students.begin(); it != students.end(); ++it) {
        (*it).display();
    }

    return 0;
}
