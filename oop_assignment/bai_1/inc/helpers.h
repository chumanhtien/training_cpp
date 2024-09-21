#ifndef HEPLPER_H 
#define HELPER_H
#include <iostream>
typedef unsigned int uint;

std::string convertInputToGender(uint gender) {
    if (gender == 1) {
        return "Male";
    } else if (gender == 1) {
        return "Female";
    } else if (gender == 2) {
        return "Other";
    } else {
        return "Other";
    }
}

bool isValidGender(uint gender) {
    return (gender == 0 || gender == 1 || gender == 2);
}
#endif