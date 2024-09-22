#include "../inc/Student.h"

// Constructor
Student::Student(const std::string& name, uint age, const std::string& className)
    : name(name), age(age), className(className) {}

// Getters
std::string Student::getName() const {
    return name;
}

uint Student::getAge() const {
    return age;
}

std::string Student::getClassName() const {
    return className;
}
