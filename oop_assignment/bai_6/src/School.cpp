#include "../inc/School.h"
#include <iostream>

void School::addStudent(std::unique_ptr<Student> student) {
    students.push_back(std::move(student));  // Sử dụng std::move để chuyển quyền sở hữu unique_ptr
}

std::vector<std::unique_ptr<Student>> School::getStudentsByAge(uint age) {
    std::vector<std::unique_ptr<Student>> result;

    for (const auto &student : students) {
        if (student->getAge() == age) {
            // Tạo bản sao
            result.push_back(std::make_unique<Student>(student->getClassName(), student->getName(), student->getAge(), student->getHometown()));
        }
    }
    return result;
}

std::vector<std::unique_ptr<Student>> School::getStudentsByAgeAndHometown(uint age, const std::string &hometown) {
    std::vector<std::unique_ptr<Student>> result;

    for (const auto &student : students) {
        if (student->getAge() == age && student->getHometown() == hometown) {
            // Tạo bản sao
            result.push_back(std::make_unique<Student>(student->getClassName(), student->getName(), student->getAge(), student->getHometown()));
        }
    }
    return result; 
}
