#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include "Employee.h"

class Experience : public Employee {
private:
    uint yearsOfExperience;
    std::string skill;

public:
    // Constructor
    Experience(const std::string& id, const std::string& fullName, const std::string& birthday, 
               const std::string& phone, const std::string& email, uint yearsOfExperience, const std::string& skill,
               const std::list<Certificate>& listCertificates = {});

    // Getters
    uint getYearsOfExperience() const;
    const std::string& getSkill() const;


    // setters
    void setYearsOfExperience(uint newYears);
    void setSkill(const std::string& newSkill);

    // Phương thức showInfo
    void showInfo() const override;
};

#endif
