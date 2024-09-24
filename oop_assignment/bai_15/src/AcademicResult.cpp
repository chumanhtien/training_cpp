#include "../inc/AcademicResult.h"
#include <iostream>

AcademicResult::AcademicResult() : semesterName(""), averageGrade(0.0) {} // Hàm khởi tạo mặc định

AcademicResult::AcademicResult(const std::string &semName, double avgGrade)
    : semesterName(semName), averageGrade(avgGrade) {}

double AcademicResult::getAverageGrade() const {
    return averageGrade;
}

const std::string &AcademicResult::getSemesterName() const {
    return semesterName;
}

void AcademicResult::printInfo() const {
    std::cout << "Semester: " << semesterName << ", Average Grade: " << averageGrade << '\n';
}