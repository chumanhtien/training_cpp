#include "../inc/Intern.h"
#include <iostream>
#include <limits>
#include "../inc/Validator.h"

// Constructor
Intern::Intern(const std::string& id, const std::string& fullName, const std::string& birthday,
               const std::string& phone, const std::string& email, const std::string& major,
               const std::string& semester, const std::string& university, const std::list<Certificate>& listCertificates)
    : Employee(id, fullName, birthday, phone, email, 2, listCertificates), // employeeType 2 là Intern
      major(major), semester(semester), university(university) {}

// getters
const std::string& Intern::getMajor() const {
    return major;
}
const std::string& Intern::getSemester() const {
    return semester;
}
const std::string& Intern::getUniversity() const {
    return university;
}


// setters
void Intern::setMajor(const std::string& newMajor) {
    major = newMajor;
}
void Intern::setSemester(const std::string& newSemester) {
    semester = newSemester;
}
void Intern::setUniversity(const std::string& newUniversity) {
    university = newUniversity;
}

// override
void Intern::showInfo() const {
    std::cout << "Intern Employee: " << fullName << ", ID: " << id
              << ", Birthday: " << birthday << ", Phone: " << phone 
              << ", Email: " << email << "employeeType: " << employeeType
              << ", Majors: " << major << ", Semester: " << semester
              << ", University: " << university << std::endl;
    if (!certificates.empty()) {
        std::cout << "Certificates:" << std::endl;
        for (const auto& cert : certificates) {
            cert.showInfo(); // Assuming this prints out certificate details
        }
    }
}

void Intern::updateInfo() {
    std::string input;
    std::string newId = id, newFullName = fullName, newBirthday = birthday, newPhone = phone, newEmail = email;
    std::string newMajor = major, newSemester = semester, newUniversity = university;
    std::cin.ignore();
    Validator validator;
    // Bước 1: Thu thập thông tin mới từ người dùng

    // Cập nhật Full Name
    std::cout << "Current Full Name: " << fullName << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        do {
            std::cout << "Enter new Full Name: ";
            std::getline(std::cin, newFullName);
            try {
                validator.validateFullName(newFullName);
                break; // Thoát vòng lặp nếu hợp lệ
            } catch (const FullNameException& e) {
                std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
            }
        } while (true);
    }

    // Cập nhật Birthday
    std::cout << "Current Birthday: " << birthday << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        do {
            std::cout << "Enter new Birthday (YYYY-MM-DD): ";
            std::getline(std::cin, newBirthday);
            try {
                validator.validateBirthday(newBirthday);
                break; // Thoát vòng lặp nếu hợp lệ
            } catch (const BirthDayException& e) {
                std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
            }
        } while (true);
    }

    // Cập nhật Phone
    std::cout << "Current Phone: " << phone << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        do {
            std::cout << "Enter new Phone: ";
            std::getline(std::cin, newPhone);
            try {
                validator.validatePhone(newPhone);
                break; // Thoát vòng lặp nếu hợp lệ
            } catch (const PhoneException& e) {
                std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
            }
        } while (true);
    }

    // Cập nhật Email
    std::cout << "Current Email: " << email << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        do {
            std::cout << "Enter new Email: ";
            std::getline(std::cin, newEmail);
            try {
                validator.validateEmail(newEmail);
                break; // Thoát vòng lặp nếu hợp lệ
            } catch (const EmailException& e) {
                std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
            }
        } while (true);
    }

    // Cập nhật Major (Chuyên ngành)
    std::cout << "Current Major: " << major << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        std::cout << "Enter new Major: ";
        std::getline(std::cin, newMajor);
    }

    // Cập nhật Semester (Học kỳ)
    std::cout << "Current Semester: " << semester << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        std::cout << "Enter new Semester: ";
        std::getline(std::cin, newSemester);
    }

    // Cập nhật University (Trường đại học)
    std::cout << "Current University: " << university << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        std::cout << "Enter new University: ";
        std::getline(std::cin, newUniversity);
    }

    // Bước 2: Hiển thị lại thông tin mới để xác nhận
    std::cout << "\nReview the new information:\n";
    std::cout << "ID: " << newId << "\n";
    std::cout << "Full Name: " << newFullName << "\n";
    std::cout << "Birthday: " << newBirthday << "\n";
    std::cout << "Phone: " << newPhone << "\n";
    std::cout << "Email: " << newEmail << "\n";
    std::cout << "Major: " << newMajor << "\n";
    std::cout << "Semester: " << newSemester << "\n";
    std::cout << "University: " << newUniversity << "\n";

    // Bước 3: Xác nhận cập nhật
    std::cout << "\nDo you want to update this information? (y/n): ";
    std::getline(std::cin, input);

    if (input == "y" || input == "Y") {
        // Thực hiện cập nhật nếu người dùng xác nhận
        setId(newId);
        setFullName(newFullName);
        setBirthday(newBirthday);
        setPhone(newPhone);
        setEmail(newEmail);
        setMajor(newMajor);
        setSemester(newSemester);
        setUniversity(newUniversity);

        std::cout << "Employee information updated successfully!\n";
    } else {
        std::cout << "Update cancelled.\n";
    }
}
