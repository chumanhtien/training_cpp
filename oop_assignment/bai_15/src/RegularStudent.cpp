#include "../inc/RegularStudent.h"
#include <iostream>

RegularStudent::RegularStudent(const std::string &id, const std::string &name, const std::string &dob,
                               uint year, double score, const std::map<std::string, AcademicResult> &results) 
    : Student(id, name, dob, year, score, results) {}

bool RegularStudent::isRegularStudent() const {
    return true; // Luôn trả về true cho sinh viên chính quy
}

void RegularStudent::printInfo() const {
    std::cout << "Regular Student ID: " << studentId << ", Name: " << fullName 
              << ", DOB: " << dateOfBirth << ", Enrollment Year: " << enrollmentYear 
              << ", Entry Score: " << entryScore << std::endl;
    
    if (!results.empty()) {
        std::cout << "Results:\n";
        for (const auto& result : results) {
            result.second.printInfo(); // Access the value of the map (AcademicResult)
        }
    }
    std::cout << '\n';
}
