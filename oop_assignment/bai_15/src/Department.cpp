#include "../inc/Department.h"
#include <iostream>

Department::Department(const std::string &name) : departmentName(name) {}

void Department::addStudent(const std::shared_ptr<Student> &student) {
    studentList.push_back(student);
}

int Department::getRegularStudentCount() const {
    int count = 0;
    for (const auto& student : studentList) {
        if (student->isRegularStudent()) {
            ++count;
        }
    }
    return count;
}

std::shared_ptr<Student> Department::getHighestEntryScoreStudent() const {
    if (studentList.empty()) return nullptr;

    auto highestStudent = studentList[0];
    for (const auto& student : studentList) {
        if (student->getEntryScore() > highestStudent->getEntryScore()) {
            highestStudent = student;
        }
    }
    return highestStudent;
}

std::vector<std::shared_ptr<PartTimeStudent>> Department::getPartTimeStudentsByAffiliation(const std::string &affiliation) const {
    std::vector<std::shared_ptr<PartTimeStudent>> result;
    for (const auto& student : studentList) {
        if (auto partTimeStudent = std::dynamic_pointer_cast<PartTimeStudent>(student)) {
            if (partTimeStudent->getAffiliation() == affiliation) {
                result.push_back(partTimeStudent);
            }
        }
    }
    return result;
}

std::vector<std::shared_ptr<Student>> Department::getTopStudentsWithLatestAverageGrade(double minGrade) const {
    std::vector<std::shared_ptr<Student>> result;
    for (const auto& student : studentList) {
        if (student->getLatestAverageGrade() >= minGrade) {
            result.push_back(student);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Student>> Department::getStudentsWithLatestAverageGrade(const std::string &semester, double minGrade) const {
    std::vector<std::shared_ptr<Student>> result;
    for (const auto &student : studentList) {
        if (student->getLatestAverageGrade() >= minGrade) {
            result.push_back(student);
        }
    }
    return result;
}

std::shared_ptr<Student> Department::getTopStudent() const {
    std::shared_ptr<Student> topStudent = nullptr;
    double highestAverage = 0.0;

    for (const auto& student : studentList) {
        double average = student->getLatestAverageGrade();
        if (average > highestAverage) {
            highestAverage = average;
            topStudent = student;
        }
    }
    return topStudent;
}

void Department::sortStudents() {
    std::sort(studentList.begin(), studentList.end(), compareStudents);
}

std::map<int, int> Department::studentStatisticsByYear() const {
    std::map<int, int> statistics;
    for (const auto& student : studentList) {
        int year = student->getEnrollmentYear();
        statistics[year]++;
    }
    return statistics;
}

void Department::printStudentList() const {
    for (const auto& student : studentList) {
        student->printInfo();
    }
}

bool Department::compareStudents(const std::shared_ptr<Student>& a, const std::shared_ptr<Student>& b) {
    if (a->isRegularStudent() != b->isRegularStudent()) {
        return a->isRegularStudent(); // Chính quy trước
    }
    return a->getEnrollmentYear() > b->getEnrollmentYear(); // Năm vào học giảm dần
}
