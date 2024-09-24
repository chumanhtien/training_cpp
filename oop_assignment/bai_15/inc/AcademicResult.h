#ifndef ACADEMIC_RESULT_H
#define ACADEMIC_RESULT_H

#include <string>

typedef unsigned int uint;

class AcademicResult {
private:
    std::string semesterName;
    double averageGrade;

public:
    AcademicResult();
    AcademicResult(const std::string &semName, double avgGrade);
    double getAverageGrade() const;
    const std::string &getSemesterName() const;
    void printInfo() const;
};

#endif // ACADEMIC_RESULT_H
