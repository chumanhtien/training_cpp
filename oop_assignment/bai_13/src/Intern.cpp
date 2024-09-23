#include "../inc/Intern.h"
#include <iostream>

// Constructor
Intern::Intern(const std::string& id, const std::string& fullName, const std::string& birthday,
               const std::string& phone, const std::string& email, const std::string& major,
               const std::string& semester, const std::string& university, const std::list<Certificate>& listCertificates)
    : Employee(id, fullName, birthday, phone, email, 2, listCertificates), // employeeType 2 là Intern
      major(major), semester(semester), university(university) {}

// getters
const std::string& Intern::getMajor() const {
    return major;
}
const std::string& Intern::getSemester() const {
    return semester;
}
const std::string& Intern::getUniversity() const {
    return university;
}


// setters
void Intern::setMajor(const std::string& newMajor) {
    major = newMajor;
}
void Intern::setSemester(const std::string& newSemester) {
    semester = newSemester;
}
void Intern::setUniversity(const std::string& newUniversity) {
    university = newUniversity;
}

// override
void Intern::showInfo() const {
    std::cout << "Intern Employee: " << fullName << ", ID: " << id
              << ", Majors: " << major
              << ", Semester: " << semester
              << ", University: " << university << std::endl;
}
