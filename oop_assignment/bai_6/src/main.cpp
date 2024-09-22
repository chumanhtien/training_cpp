#include <iostream>
#include <memory>
#include "../inc/School.h"

int main() {
    School school;

    // add students to school
    school.addStudent(std::make_unique<Student>("10A1", "Nguyen Van A", 20, "DN"));
    school.addStudent(std::make_unique<Student>("10A1", "Tran Thi B", 21, "HN"));
    school.addStudent(std::make_unique<Student>("10A2", "Le Van C", 20, "DN"));
    school.addStudent(std::make_unique<Student>("10A2", "Nguyen Van D", 23, "DN"));
    school.addStudent(std::make_unique<Student>("10A3", "Pham Thi E", 23, "HCM"));

    // student with age = 20
    std::cout << "Student with age 20 years old:\n";
    auto students20 = school.getStudentsByAge(20);
    for (const auto& student : students20) {
        std::cout << student->getName() << " - " << student->getClassName() << "\n";
    }

    // Number of students with 23 years old and hometown in DN
    uint count23InDN = school.getStudentsByAgeAndHometown(23, "DN").size();
    std::cout << "Number of students with 23 years old and hometown in DN is: " << count23InDN << "\n";

    return 0;
}
