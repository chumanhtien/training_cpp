// student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int age;
    float gpa;

public:
    Student(const std::string& name, int age, float gpa);

    std::string getName() const;
    int getAge() const;
    float getGPA() const;

    void setName(const std::string& name);
    void setAge(int age);
    void setGPA(float gpa);

    void display() const;
};

#endif
