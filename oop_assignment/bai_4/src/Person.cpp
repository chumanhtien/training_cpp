#include "../inc/Person.h"

Person::Person(std::string name, uint age, std::string career, std::string identityNumber) :
    name(name), age(age), career(career), identityNumber(identityNumber) {}

Person::~Person() {
    std::cout << "Person destructor is called\n";
}

std::string Person::getName() const {
    return name;
}

uint Person::getAge() const {
    return age;
}

std::string Person::getCareer() const {
    return career;
}

std::string Person::getIdentityNumber() const {
    return identityNumber;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAge(uint age) {
    this->age = age;
}

void Person::setCareer(const std::string& career) {
    this->career = career;
}

void Person::setIdentityNumber(const std::string& identityNumber) {
    this->identityNumber = identityNumber;
}

std::string Person::toString() const {
    return "Name: " + name + ", Age: " + std::to_string(age) + 
           ", Career: " + career + ", Identity Number: " + identityNumber;
}