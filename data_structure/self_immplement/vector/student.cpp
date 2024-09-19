// Student.cpp
#include "student.h"
#include <iostream>

Student::Student(const std::string& name, int age, float gpa)
    : name(name), age(age), gpa(gpa) {}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

float Student::getGPA() const {
    return gpa;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setGPA(float gpa) {
    this->gpa = gpa;
}

void Student::display() const {
    std::cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << std::endl;
}
