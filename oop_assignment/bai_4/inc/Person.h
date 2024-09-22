#ifndef PERSON_H
#define PERSON_H
#include <memory>
#include <string>
#include <iostream>


typedef unsigned int uint;
class Person {
private:
    std::string name;
    uint age;
    std::string career;
    std::string identityNumber; // unique

public:
    Person(std::string name, uint age, std::string career, std::string identityNumber);
    ~Person();

    // getter
    std::string getName() const;
    uint getAge() const;
    std::string getCareer() const;
    std::string getIdentityNumber() const;

    // setter
    void setName(const std::string& name);
    void setCareer(const std::string& career);
    void setAge(uint age);
    void setIdentityNumber(const std::string& identityNumber);

    // display
    // Method to display person information
    std::string toString() const;
};
#endif