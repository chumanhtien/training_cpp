#ifndef REGULAR_STUDENT_H
#define REGULAR_STUDENT_H

#include "Student.h"

class RegularStudent : public Student {
public:
    RegularStudent(const std::string &id, const std::string &name, const std::string &dob,
                   uint year, double score, const std::map<std::string, AcademicResult> &results = {});

    bool isRegularStudent() const override;
    void printInfo() const override;
};

#endif // REGULAR_STUDENT_H
