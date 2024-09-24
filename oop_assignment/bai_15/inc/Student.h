#ifndef STUDENT_H
#define STUDENT_H

#include "AcademicResult.h"
#include <map>
#include <string>
#include <memory>

class Student {
protected:
    std::string studentId;
    std::string fullName;
    std::string dateOfBirth;
    uint enrollmentYear;
    double entryScore;
    std::map<std::string, AcademicResult> results;

public:
    Student(const std::string &id, const std::string &name, const std::string &dob,
            uint year, double score, const std::map<std::string, AcademicResult>& results = std::map<std::string, AcademicResult>());
    virtual ~Student() = default; // Destructor for polymorphism

    virtual bool isRegularStudent() const = 0; // Pure virtual functionAcademicResult
    double getSemesterAverageGrade(const std::string &semester) const;
    void addResult(const AcademicResult &result);
    double getLatestAverageGrade() const;
    double getEntryScore() const;
    int getEnrollmentYear() const;
    const std::string &getStudentId() const;
    virtual void printInfo() const = 0; // Pure virtual function for info printing
};

#endif // STUDENT_H
