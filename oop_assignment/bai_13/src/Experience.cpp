#include "../inc/Experience.h"
#include <limits>
#include "../inc/Validator.h"

// Constructor
Experience::Experience(const std::string& id, const std::string& fullName, const std::string& birthday, 
                       const std::string& phone, const std::string& email, uint yearsOfExperience, const std::string& skill,
                       const std::list<Certificate>& listCertificates)
    : Employee(id, fullName, birthday, phone, email, 1, listCertificates), yearsOfExperience(yearsOfExperience), skill(skill) {}

// getters
uint Experience::getYearsOfExperience() const {
    return yearsOfExperience;
}
const std::string& Experience::getSkill() const {
    return skill;
}

// setters
void Experience::setYearsOfExperience(uint newYears) {
    yearsOfExperience = newYears;
}
void Experience::setSkill(const std::string& newSkill) {
    skill = newSkill;
}

// override
void Experience::showInfo() const {
    std::cout << "Experience Employee: " << fullName << ", ID: " << id 
              << ", Birthday: " << birthday << ", Phone: " << phone 
              << ", Email: " << email << "employeeType: " << employeeType
              << ", Skill: " << skill << ", Years of Experience: " << yearsOfExperience << std::endl;
    if (!certificates.empty()) {
        std::cout << "Certificates:" << std::endl;
        for (const auto& cert : certificates) {
            cert.showInfo(); // Assuming this prints out certificate details
        }
    }
}

void Experience::updateInfo() {
    std::string input;
    std::string newFullName = fullName, newBirthday = birthday, newPhone = phone, newEmail = email;
    uint newYearsOfExperience = yearsOfExperience;
    std::string newSkill = skill;
    std::cin.ignore();
    Validator validator;
    // std::cin.clear();


    // B1: thu thap thong tin moi nhap
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

    // Cập nhật Years of Experience
    std::cout << "Current Years of Experience: " << yearsOfExperience << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        do {
            std::cout << "Enter new Years of Experience: ";
            while (!(std::cin >> newYearsOfExperience)) {
                std::cout << "Invalid input. Please enter a valid number for Years of Experience: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Xóa bộ đệm
            break; // Thoát vòng lặp nếu hợp lệ
        } while (true);
    }

    // Cập nhật Skill
    std::cout << "Current Skill: " << skill << ". Do you want to update it? (y/n): ";
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        std::cout << "Enter new Skill: ";
        std::getline(std::cin, newSkill);
    }

    // Bước 2: Hiển thị lại thông tin mới để xác nhận
    std::cout << "\nReview the new information:\n";
    std::cout << "Full Name: " << newFullName << "\n";
    std::cout << "Birthday: " << newBirthday << "\n";
    std::cout << "Phone: " << newPhone << "\n";
    std::cout << "Email: " << newEmail << "\n";
    std::cout << "Years of Experience: " << newYearsOfExperience << "\n";
    std::cout << "Skill: " << newSkill << "\n";

    // Bước 3: Xác nhận cập nhật
    std::cout << "\nDo you want to update this information? (y/n): ";
    std::getline(std::cin, input);

    if (input == "y" || input == "Y") {
        // Thực hiện cập nhật nếu người dùng xác nhận
        setFullName(newFullName);
        setBirthday(newBirthday);
        setPhone(newPhone);
        setEmail(newEmail);
        setYearsOfExperience(newYearsOfExperience);
        setSkill(newSkill);

        std::cout << "Employee information updated successfully!\n";
    } else {
        std::cout << "Update cancelled.\n";
    }
}
