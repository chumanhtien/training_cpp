#include "../inc/Employee.h"

uint Employee::employeeCount = 0;

// Constructor
Employee::Employee(const std::string& id, const std::string& fullName, const std::string& birthday, 
                   const std::string& phone, const std::string& email, uint type,
                   const std::list<Certificate>& listCertificates) :
    id(id), fullName(fullName), birthday(birthday), phone(phone), email(email), employeeType(type), certificates(listCertificates) {
    employeeCount++;
}

// Destructor
Employee::~Employee() {
    employeeCount--;
}

// Getter methods
const std::string& Employee::getId() const {
    return id;
}
const std::string& Employee::getFullName() const {
    return fullName;
}

const std::string& Employee::getBirthday() const {
    return birthday;
}
const std::string& Employee::getPhone() const {
    return phone;
}
const std::string& Employee::getEmail() const {
    return email;
}
uint Employee::getEmployeeType() const {
    return employeeType;
}
const std::list<Certificate>& Employee::getCertificates() const {
    return certificates;
}

// Setter methods
void Employee::setId(const std::string& newId) {
    id = newId;
}
void Employee::setFullName(const std::string& newFullName) {
    fullName = newFullName;
}
void Employee::setBirthday(const std::string& newBirthday) {
    birthday = newBirthday;
}
void Employee::setPhone(const std::string& newPhone) {
    phone = newPhone;
}
void Employee::setEmail(const std::string& newEmail) {
    email = newEmail;
}
void Employee::setEmployeeType(uint newEmployeeType) {
    employeeType = newEmployeeType;
}
void Employee::addCertificate(const Certificate& certificate) {
    certificates.push_back(certificate); // Thêm chứng chỉ vào danh sách
}

void Employee::removeCertificate(const std::string& certificateId) {
    for (auto it = certificates.begin(); it != certificates.end(); ) {
        if (it->getCertificateId() == certificateId) {
            it = certificates.erase(it);
        } else {
            ++it; // Chỉ chuyển sang phần tử tiếp theo nếu không xóa
        }
    }
}