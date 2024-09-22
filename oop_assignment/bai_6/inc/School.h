#ifndef SCHOOL_H
#define SCHOOL_H
#include "Student.h"
#include <vector>
#include <memory>

class School {
private:
    std::vector<std::unique_ptr<Student>> students;

public:
    void addStudent(std::unique_ptr<Student> student);

    std::vector<std::unique_ptr<Student>> getStudentsByAge(uint age);
    std::vector<std::unique_ptr<Student>> getStudentsByAgeAndHometown(uint age, const std::string& homeTown);
};
#endif