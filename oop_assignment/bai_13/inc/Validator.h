#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include "Exception.h"

class Validator {
public:
    static void validateBirthday(const std::string& birthday);
    static void validateDate(const std::string& birthday);
    static void validatePhone(const std::string& phone);
    static void validateEmail(const std::string& email);
    static void validateFullName(const std::string& fullName);
};

#endif
