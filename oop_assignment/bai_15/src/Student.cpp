#include "../inc/Student.h"

Student::Student(const std::string& id, const std::string& name, const std::string& dob,
            uint year, double score, const std::map<std::string, AcademicResult>& results) : 
        studentId(id), fullName(name), dateOfBirth(dob), enrollmentYear(year), 
      entryScore(score), results(results) {}

double Student::getSemesterAverageGrade(const std::string &semester) const {
    auto it = results.find(semester);
    if (it != results.end()) {
        return it->second.getAverageGrade(); // Use the value in the map (AcademicResult)
    }
    return 0.0; // Return 0 if semester not found
}

void Student::addResult(const AcademicResult &result) {
    results[result.getSemesterName()] = result;
}

double Student::getLatestAverageGrade() const {
    if (!results.empty()) {
        // The latest result can be determined based on the lexicographical order of semester keys
        return results.rbegin()->second.getAverageGrade();
    }
    return 0.0;
}

double Student::getEntryScore() const {
    return entryScore;
}

int Student::getEnrollmentYear() const {
    return enrollmentYear;
}

const std::string &Student::getStudentId() const {
    return studentId;
}
