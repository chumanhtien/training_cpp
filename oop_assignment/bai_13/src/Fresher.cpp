#include "../inc/Fresher.h"
#include <iostream>

// Constructor
Fresher::Fresher(const std::string& id, const std::string& fullName, const std::string& birthday,
                 const std::string& phone, const std::string& email, const std::string& graduationDate,
                 const std::string& graduationRank, const std::string& education, const std::list<Certificate>& listCertificates)
    : Employee(id, fullName, birthday, phone, email, 2, listCertificates), // employeeType 2 là Fresher
      graduationDate(graduationDate), graduationRank(graduationRank), education(education) {}

// Getter và setter cho thuộc tính graduationDate
const std::string& Fresher::getGraduationDate() const {
    return graduationDate;
}

void Fresher::setGraduationDate(const std::string& newGraduationDate) {
    graduationDate = newGraduationDate;
}

// Getter và setter cho thuộc tính graduationRank
const std::string& Fresher::getGraduationRank() const {
    return graduationRank;
}

void Fresher::setGraduationRank(const std::string& newGraduationRank) {
    graduationRank = newGraduationRank;
}

// Getter và setter cho thuộc tính education
const std::string& Fresher::getEducation() const {
    return education;
}

void Fresher::setEducation(const std::string& newEducation) {
    education = newEducation;
}

// override
void Fresher::showInfo() const {
    std::cout << "Fresher Employee: " << fullName << ", ID: " << id
              << ", Graduation Date: " << graduationDate
              << ", Graduation Rank: " << graduationRank
              << ", Education: " << education << std::endl;
}
