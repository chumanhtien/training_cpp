#include "../inc/Experience.h"

// Constructor
Experience::Experience(const std::string& id, const std::string& fullName, const std::string& birthday, 
                       const std::string& phone, const std::string& email, uint yearsOfExperience, const std::string& skill,
                       const std::list<Certificate>& listCertificates)
    : Employee(id, fullName, birthday, phone, email, 1, listCertificates), yearsOfExperience(yearsOfExperience), skill(skill) {}

// getters
uint Experience::getYearsOfExperience() const {
    return yearsOfExperience;
}
const std::string& Experience::getSkill() const {
    return skill;
}

// setters
void Experience::setYearsOfExperience(uint newYears) {
    yearsOfExperience = newYears;
}
void Experience::setSkill(const std::string& newSkill) {
    skill = newSkill;
}

// override
void Experience::showInfo() const {
    std::cout << "Experience Employee: " << fullName << ", ID: " << id 
              << ", Skill: " << skill << ", Years of Experience: " << yearsOfExperience << std::endl;
}
