#include "../inc/Fresher.h"
#include <iostream>
#include <limits>
#include "../inc/Validator.h"

// Constructor
Fresher::Fresher(const std::string& id, const std::string& fullName, const std::string& birthday,
                 const std::string& phone, const std::string& email, const std::string& graduationDate,
                 const std::string& graduationRank, const std::string& education, const std::list<Certificate>& listCertificates)
    : Employee(id, fullName, birthday, phone, email, 2, listCertificates), // employeeType 2 là Fresher
      graduationDate(graduationDate), graduationRank(graduationRank), education(education) {}

// Getter và setter cho thuộc tính graduationDate
const std::string& Fresher::getGraduationDate() const {
    return graduationDate;
}

void Fresher::setGraduationDate(const std::string& newGraduationDate) {
    graduationDate = newGraduationDate;
}

// Getter và setter cho thuộc tính graduationRank
const std::string& Fresher::getGraduationRank() const {
    return graduationRank;
}

void Fresher::setGraduationRank(const std::string& newGraduationRank) {
    graduationRank = newGraduationRank;
}

// Getter và setter cho thuộc tính education
const std::string& Fresher::getEducation() const {
    return education;
}

void Fresher::setEducation(const std::string& newEducation) {
    education = newEducation;
}

// override
void Fresher::showInfo() const {
    std::cout << "Fresher Employee: " << fullName << ", ID: " << id
              << ", Birthday: " << birthday << ", Phone: " << phone 
              << ", Email: " << email << "employeeType: " << employeeType
              << ", Graduation Date: " << graduationDate
              << ", Graduation Rank: " << graduationRank
              << ", Education: " << education << std::endl;
    if (!certificates.empty()) {
        std::cout << "Certificates:" << std::endl;
        for (const auto& cert : certificates) {
            cert.showInfo(); // Assuming this prints out certificate details
        }
    }
}

// Phương thức updateInfo
void Fresher::updateInfo() {
    std::string input;
    std::string newId = id, newFullName = fullName, newBirthday = birthday, newPhone = phone, newEmail = email;
    std::string newGraduationDate = graduationDate, newGraduationRank = graduationRank, newEducation = education;
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

    // Cập nhật Graduation Date
    std::cout << "Current Graduation Date: " << graduationDate << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        std::cout << "Enter new Graduation Date: ";
        std::getline(std::cin, newGraduationDate);
    }

    // Cập nhật Graduation Rank
    std::cout << "Current Graduation Rank: " << graduationRank << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        std::cout << "Enter new Graduation Rank: ";
        std::getline(std::cin, newGraduationRank);
    }

    // Cập nhật Education
    std::cout << "Current Education: " << education << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        std::cout << "Enter new Education: ";
        std::getline(std::cin, newEducation);
    }

    // Bước 2: Hiển thị lại thông tin mới để xác nhận
    std::cout << "\nReview the new information:\n";
    std::cout << "ID: " << newId << "\n";
    std::cout << "Full Name: " << newFullName << "\n";
    std::cout << "Birthday: " << newBirthday << "\n";
    std::cout << "Phone: " << newPhone << "\n";
    std::cout << "Email: " << newEmail << "\n";
    std::cout << "Graduation Date: " << newGraduationDate << "\n";
    std::cout << "Graduation Rank: " << newGraduationRank << "\n";
    std::cout << "Education: " << newEducation << "\n";

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
        setGraduationDate(newGraduationDate);
        setGraduationRank(newGraduationRank);
        setEducation(newEducation);

        std::cout << "Employee information updated successfully!\n";
    } else {
        std::cout << "Update cancelled.\n";
    }
}