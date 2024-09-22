#ifndef STUDENT_H
#define STUDENT_H

#include <string>
typedef unsigned int uint;

class Student {
private:
    std::string name;
    uint age;
    std::string className;

public:
    Student(const std::string& name, uint age, const std::string& className);

    // Getters
    std::string getName() const;
    uint getAge() const;
    std::string getClassName() const;

    std::string getInfo() const;
};

#endif
