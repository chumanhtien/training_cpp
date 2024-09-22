#ifndef STUDENT_H
#define STUDENT_H

#include <string>

typedef unsigned int uint;

class Student {
private:
    std::string className;
    std::string name;
    uint age;
    std::string hometown;

public:
    // Constructor
    Student(const std::string& className, const std::string& name, uint age, const std::string& hometown);

    // Destructor
    ~Student();

    // Getters
    std::string getClassName() const;
    std::string getName() const;
    uint getAge() const;
    std::string getHometown() const;

    // Setters
    void setClassName(std::string& className);
    void setName(std::string& name);
    void setAge(uint age);
    void setHometown(std::string& hometown);

    // get infor
    std::string toString() const;
};

#endif
