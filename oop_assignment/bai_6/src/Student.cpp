#include "../inc/Student.h"
#include <iostream>
using namespace std;

// Constructor
Student::Student(const string& className, const string& name, uint age, const string& hometown) :
    className(className), name(name), age(age), hometown(hometown) {}

// Destructor
Student::~Student() {
    cout << "Student destructor is called.\n";
}

// Getters
string Student::getClassName() const {
    return className;
}

string Student::getName() const {
    return name;
}

uint Student::getAge() const {
    return age;
}

string Student::getHometown() const {
    return hometown;
}

// Setters
void Student::setClassName(string& className) {
    this->className = className;
}

void Student::setName(string& name) {
    this->name = name;
}

void Student::setAge(uint age) {
    this->age = age;
}

void Student::setHometown(string& hometown) {
    this->hometown = hometown;
}

// Phương thức toString trả về thông tin sinh viên dưới dạng chuỗi
string Student::toString() const {
    string str;
    str += "Class Name: " + className + ", Name: " + name + ", Age: " + to_string(age) + ", Hometown: " + hometown;
    return str;
}
