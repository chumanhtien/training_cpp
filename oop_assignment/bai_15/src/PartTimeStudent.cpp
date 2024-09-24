#include "../inc/PartTimeStudent.h"
#include <iostream>

PartTimeStudent::PartTimeStudent(const std::string &id, const std::string &name, const std::string &dob,
                                 uint year, double score, const std::string &affiliation,
                                 const std::map<std::string, AcademicResult> &results) 
    : Student(id, name, dob, year, score, results), affiliation(affiliation) {}

bool PartTimeStudent::isRegularStudent() const {
    return false; // Luôn trả về false cho sinh viên tại chức
}

const std::string &PartTimeStudent::getAffiliation() const {
    return affiliation;
}

void PartTimeStudent::printInfo() const {
    std::cout << "Part-Time Student ID: " << studentId << ", Name: " << fullName 
              << ", DOB: " << dateOfBirth << ", Enrollment Year: " << enrollmentYear 
              << ", Entry Score: " << entryScore << ", Affiliation: " << affiliation << std::endl;
    
    if (!results.empty()) {
        std::cout << "Results:\n";
        for (const auto& result : results) {
            result.second.printInfo(); // Access the value of the map (AcademicResult)
        }
    }
    std::cout << '\n';
}
