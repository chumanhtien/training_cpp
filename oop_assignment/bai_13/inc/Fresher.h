#ifndef FRESHER_H
#define FRESHER_H

#include "Employee.h"
#include <string>

class Fresher : public Employee {
private:
    std::string graduationDate;
    std::string graduationRank;
    std::string education;

public:
    // Constructor
    Fresher(const std::string& id, const std::string& fullName, const std::string& birthday,
            const std::string& phone, const std::string& email, const std::string& graduationDate,
            const std::string& graduationRank, const std::string& education, const std::list<Certificate>& listCertificates = {});

    // getters
    const std::string& getGraduationDate() const;
    const std::string& getGraduationRank() const;
    const std::string& getEducation() const;

    // setters
    void setGraduationDate(const std::string& newGraduationDate);
    void setGraduationRank(const std::string& newGraduationRank);
    void setEducation(const std::string& newEducation);

    // Phương thức showInfo
    void showInfo() const override;
};

#endif
