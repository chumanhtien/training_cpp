#ifndef PARTTIME_STUDENT_H
#define PARTTIME_STUDENT_H

#include "Student.h"

class PartTimeStudent : public Student {
private:
    std::string affiliation; // Nơi liên kết đào tạo

public:
    PartTimeStudent(const std::string &id, const std::string &name, const std::string &dob,
                    uint year, double score, const std::string &affiliation, 
                    const std::map<std::string, AcademicResult> &results = {});

    bool isRegularStudent() const override;
    const std::string &getAffiliation() const;
    void printInfo() const override;
};

#endif // PARTTIME_STUDENT_H
