#ifndef INTERN_H
#define INTERN_H

#include "Employee.h"
#include <string>

class Intern : public Employee {
private:
    std::string major;      // Chuyên ngành đang học
    std::string semester;    // Học kỳ đang học
    std::string university;  // Tên trường đang học

public:
    // Constructor
    Intern(const std::string& id, const std::string& fullName, const std::string& birthday,
           const std::string& phone, const std::string& email, const std::string& major,
           const std::string& semester, const std::string& university, const std::list<Certificate>& listCertificates = {});

    // Getters
    const std::string& getMajor() const;
    const std::string& getSemester() const;
    const std::string& getUniversity() const;

    // setters
    void setMajor(const std::string& newMajor);
    void setSemester(const std::string& newSemester);
    void setUniversity(const std::string& newUniversity);

    void showInfo() const override;
    void updateInfo() override;
};

#endif
