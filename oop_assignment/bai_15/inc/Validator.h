#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include "Exception.h"

class Validator {
public:
    static void validateBirthday(const std::string& birthday);
    static void validateEntryScore(const double& entryScore);
    static void validateEnrollmentYear(const uint& enrollmentYear);
    static void validateFullName(const std::string& fullName);
    static void validateSemesterName(const std::string& semesterName);
};

#endif
