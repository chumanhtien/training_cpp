#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Student.h"
#include "PartTimeStudent.h"
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

class Department {
private:
    std::string departmentName;
    std::vector<std::shared_ptr<Student>> studentList;

public:
    Department(const std::string &name);

    void addStudent(const std::shared_ptr<Student> &student);
    int getRegularStudentCount() const;
    std::shared_ptr<Student> getHighestEntryScoreStudent() const;
    std::vector<std::shared_ptr<PartTimeStudent>> getPartTimeStudentsByAffiliation(const std::string &affiliation) const;
    std::vector<std::shared_ptr<Student>> getTopStudentsWithLatestAverageGrade(double minGrade) const;
    std::shared_ptr<Student> getTopStudent() const;
    void sortStudents();
    std::map<int, int> studentStatisticsByYear() const;
    void printStudentList() const;
    std::vector<std::shared_ptr<Student>> getStudentsWithLatestAverageGrade(const std::string &semester, double minGrade) const;

    // Hàm so sánh sinh viên
    static bool compareStudents(const std::shared_ptr<Student>& a, const std::shared_ptr<Student>& b);
};

#endif // DEPARTMENT_H
