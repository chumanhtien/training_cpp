#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <string>
#include <exception>
#include "../inc/Department.h"
#include "../inc/RegularStudent.h"
#include "../inc/PartTimeStudent.h"
#include "../inc/AcademicResult.h"
#include "../inc/Validator.h"

using namespace std;

void inputAcademicResults(map<string, AcademicResult> &results) {
    int n;
    Validator validator;
    cout << "Enter number of academic results: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string semester;
        double averageGrade;
        do {
            cout << "Enter semester name: ";
            getline(cin, semester);
            try {
                validator.validateSemesterName(semester);
                break; // Thoát vòng lặp nếu hợp lệ
            } catch (const SemesterNameException& e) {
                std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
            }
        } while (true);

        do {
            cout << "Enter average grade: ";
            cin >> averageGrade; cin.ignore();
            try {
                validator.validateEntryScore(averageGrade);
                break; // Thoát vòng lặp nếu hợp lệ
            } catch (const EntryCoreException& e) {
                std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
            }
        } while (true);
        AcademicResult result(semester, averageGrade);
        // Insert into the map using semester as the key and result as the value
        results.emplace(semester, result); 
    }
}

void inputStudent(shared_ptr<Student> &student) {
    string id, name, dob;
    uint year;
    double score;
    string affiliation;
    Validator validator;

    cout << "Enter student ID: ";
    getline(cin, name);

    do {
        cout << "Enter full name: ";
        getline(cin, name);
        try {
            validator.validateFullName(name);
            break; // Thoát vòng lặp nếu hợp lệ
        } catch (const FullNameException& e) {
            std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
        }
    } while (true);

    do {
        std::cout << "Enter date of birth (YYYY-MM-DD):";
        std::getline(std::cin, dob);
        try {
            validator.validateBirthday(dob);
            break; // Thoát vòng lặp nếu hợp lệ
        } catch (const BirthDayException& e) {
            std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
        }
    } while (true);

    do {
        std::cout << "Enter enrollment year: ";
        cin >> year; cin.ignore();
        try {
            validator.validateEnrollmentYear(year);
            break; // Thoát vòng lặp nếu hợp lệ
        } catch (const EncrollmentYearException& e) {
            std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
        }
    } while (true);

    do {
        std::cout << "Enter entry score: ";
        cin >> score; cin.ignore();
        try {
            validator.validateEntryScore(score);
            break; // Thoát vòng lặp nếu hợp lệ
        } catch (const EntryCoreException& e) {
            std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
        }
    } while (true);

    int type;
    cout << "Enter 1 for Regular Student or 2 for Part-Time Student: ";
    cin >> type;
    cin.ignore();

    map<std::string, AcademicResult> results;
    inputAcademicResults(results);

    if (type == 1) {
        student = make_shared<RegularStudent>(id, name, dob, year, score, results);
    } else {
        cout << "Enter affiliation: ";
        getline(cin, affiliation);
        student = make_shared<PartTimeStudent>(id, name, dob, year, score, affiliation, results);
    }
}

void generateTestData(Department &department) {
    // Creating unique academic results for each student
    std::map<std::string, AcademicResult> results1 = {
        {"2021.2", AcademicResult("2021.2", 7.8)},
        {"2022.1", AcademicResult("2022.1", 8.5)},
        {"2022.2", AcademicResult("2022.2", 8.0)}
    };

    std::map<std::string, AcademicResult> results2 = {
        {"2021.2", AcademicResult("2021.2", 8.1)},
        {"2022.1", AcademicResult("2022.1", 7.9)},
        {"2022.2", AcademicResult("2022.2", 8.4)}
    };

    std::map<std::string, AcademicResult> results3 = {
        {"2021.2", AcademicResult("2021.2", 7.0)},
        {"2022.1", AcademicResult("2022.1", 6.5)},
        {"2022.2", AcademicResult("2022.2", 7.3)}
    };

    std::map<std::string, AcademicResult> results4 = {
        {"2021.2", AcademicResult("2021.2", 6.9)},
        {"2022.1", AcademicResult("2022.1", 7.2)},
        {"2022.2", AcademicResult("2022.2", 7.6)}
    };

    std::map<std::string, AcademicResult> results5 = {
        {"2021.2", AcademicResult("2021.2", 8.3)},
        {"2022.1", AcademicResult("2022.1", 8.7)},
        {"2022.2", AcademicResult("2022.2", 8.9)}
    };

    std::map<std::string, AcademicResult> results6 = {
        {"2021.2", AcademicResult("2021.2", 7.2)},
        {"2022.1", AcademicResult("2022.1", 7.6)},
        {"2022.2", AcademicResult("2022.2", 8.1)}
    };

    std::map<std::string, AcademicResult> results7 = {
        {"2021.2", AcademicResult("2021.2", 6.8)},
        {"2022.1", AcademicResult("2022.1", 7.0)},
        {"2022.2", AcademicResult("2022.2", 7.4)}
    };

    std::map<std::string, AcademicResult> results8 = {
        {"2021.2", AcademicResult("2021.2", 8.5)},
        {"2022.1", AcademicResult("2022.1", 8.2)},
        {"2022.2", AcademicResult("2022.2", 9.0)}
    };

    std::map<std::string, AcademicResult> results9 = {
        {"2021.2", AcademicResult("2021.2", 7.1)},
        {"2022.1", AcademicResult("2022.1", 7.3)},
        {"2022.2", AcademicResult("2022.2", 7.9)}
    };

    std::map<std::string, AcademicResult> results10 = {
        {"2021.2", AcademicResult("2021.2", 8.9)},
        {"2022.1", AcademicResult("2022.1", 9.0)},
        {"2022.2", AcademicResult("2022.2", 9.3)}
    };
    // Adding Regular Students
    shared_ptr<Student> student1 = make_shared<RegularStudent>("S001", "Nguyen Van A", "2000-05-12", 2020, 9.0, results1);
    shared_ptr<Student> student2 = make_shared<RegularStudent>("S002", "Tran Thi B", "2001-11-23", 2021, 8.8, results2);
    shared_ptr<Student> student3 = make_shared<RegularStudent>("S003", "Le Van C", "2000-07-14", 2020, 7.5, results3);

    // Adding Part-Time Students
    shared_ptr<Student> student4 = make_shared<PartTimeStudent>("S004", "Pham Van D", "1999-02-03", 2019, 7.0, "Hanoi", results4);
    shared_ptr<Student> student5 = make_shared<PartTimeStudent>("S005", "Hoang Thi E", "2002-04-30", 2021, 8.2, "Hanoi", results5);
    shared_ptr<Student> student6 = make_shared<PartTimeStudent>("S006", "Bui Van F", "2001-09-15", 2020, 6.9, "Danang", results6);

    // Adding more students with different results and affiliations
    shared_ptr<Student> student7 = make_shared<RegularStudent>("S007", "Vu Thi G", "2001-03-10", 2021, 8.0, results7);
    shared_ptr<Student> student8 = make_shared<PartTimeStudent>("S008", "Dang Van H", "2002-08-20", 2022, 7.6, "Hanoi", results8);
    shared_ptr<Student> student9 = make_shared<RegularStudent>("S009", "Nguyen Van I", "2001-06-11", 2021, 7.4, results9);
    shared_ptr<Student> student10 = make_shared<PartTimeStudent>("S010", "Tran Thi J", "2000-12-25", 2020, 9.1, "Danang", results10);

    // Adding students to the department
    department.addStudent(student1);
    department.addStudent(student2);
    department.addStudent(student3);
    department.addStudent(student4);
    department.addStudent(student5);
    department.addStudent(student6);
    department.addStudent(student7);
    department.addStudent(student8);
    department.addStudent(student9);
    department.addStudent(student10);
}

int main() {
    Department department("Computer Science");
    generateTestData(department);

    int choice;
    do {
        cout << "---------------------------------------- MAIN PROGRAM ---------------------------------\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Get Regular Student Count\n";
        cout << "4. Get Highest Entry Score Student\n";
        cout << "5. Get Part-Time Students by Affiliation\n";
        cout << "6. Get Students with Latest Average Grade >= 8.0\n";
        cout << "7. Get Top Student by Any Semester\n";
        cout << "8. Sort Students\n";
        cout << "9. Student Statistics by Enrollment Year\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                shared_ptr<Student> student;
                inputStudent(student);
                department.addStudent(student);
                break;
            }
            case 2:
                department.printStudentList();
                break;
            case 3: {
                cout << "Total regular students: " << department.getRegularStudentCount() << endl;
                break;
            }
            case 4: {
                auto topStudent = department.getHighestEntryScoreStudent();
                if (topStudent) {
                    topStudent->printInfo();
                } else {
                    cout << "No students available." << endl;
                }
                break;
            }
            case 5: {
                string affiliation;
                cout << "Enter affiliation: ";
                cin.ignore();
                getline(cin, affiliation);
                auto partTimeStudents = department.getPartTimeStudentsByAffiliation(affiliation);
                for (const auto &s : partTimeStudents) {
                    s->printInfo();
                }
                break;
            }
            case 6: {
                // string semester;
                // cout << "Enter semester name: ";
                // cin >> semester;
                auto students = department.getTopStudentsWithLatestAverageGrade(8.0);
                for (const auto &s : students) {
                    s->printInfo();
                }
                break;
            }
            case 7: {
                auto topStudent = department.getTopStudent();
                if (topStudent) {
                    topStudent->printInfo();
                } else {
                    cout << "No students available." << endl;
                }
                break;
            }
            case 8:
                department.sortStudents();
                cout << "Students sorted." << endl;
                break;
            case 9: {
                auto stats = department.studentStatisticsByYear();
                for (const auto &entry : stats) {
                    cout << "Year: " << entry.first << ", Count: " << entry.second << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
