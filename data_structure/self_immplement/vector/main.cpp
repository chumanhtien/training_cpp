#include <iostream>
#include "vector.h"
#include "student.h"

int main() {
    // Tạo một MyVector để lưu trữ các đối tượng Student
    MyVector<Student> vec;

    // Thêm các đối tượng Student vào vector
    vec.push_back(Student("Alice", 20, 3.8));
    vec.push_back(Student("Bob", 22, 3.6));
    vec.push_back(Student("Charlie", 21, 3.9));

    // In kích thước và dung lượng của vector
    std::cout << "Vector size: " << vec.getSize() << std::endl;
    std::cout << "Vector capacity: " << vec.getCapacity() << std::endl;

    // Duyệt và hiển thị thông tin của từng sinh viên
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << "Student " << i << ": ";
        vec[i].display();
    }

    return 0;
}
