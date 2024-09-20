#include "../inc/Officer.h"

Officer::Officer() : 
    fullName("Name Default"), age(18), gender("Male"), address("NULL") {}

Officer::Officer(std::string fullName, uint age, std::string gender, std::string address) : 
    fullName(fullName), age(age), gender(gender), address(address) {}

Officer::~Officer() {
    std::cout << "Officer destructor is called\n";
}

std::string Officer::getFullName() const {
    return fullName;
}

void Officer::setFullName(std::string name) {
    this->fullName = name;
}

uint Officer::getAge() const {
    return age;
}

void Officer::setAge(uint age) {
    this->age = age;
}

std::string Officer::getGender() const {
    return gender;
}

void Officer::setGender(std::string gender) {
    this->gender = gender;
}

std::string Officer::getAddress() const {
    return address;
}

void Officer::setAddress(std::string address) {
    this->address = address;
}

std::string Officer::toString() const {
    return "Full Name: " + fullName + ", Age: " + std::to_string(age) + 
           ", Gender: " + gender + ", Address: " + address;
}