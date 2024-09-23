#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Certificate.h"
#include <list>

typedef unsigned int uint;

class Employee {
protected:
    std::string id;
    std::string fullName;
    std::string birthday;
    std::string phone;
    std::string email;
    uint employeeType;
    static uint employeeCount;
    std::list<Certificate> certificates;

public:
    // Constructor
    Employee(const std::string& id, const std::string& fullName, const std::string& birthday, 
             const std::string& phone, const std::string& email, uint type,
             const std::list<Certificate>& listCertificates = {});

    // Destructor
    virtual ~Employee();

    // Getter methods
    const std::string& getId() const;
    const std::string& getFullName() const;
    const std::string& getBirthday() const;
    const std::string& getPhone() const;
    const std::string& getEmail() const;
    uint getEmployeeType() const;
    const std::list<Certificate>& getCertificates() const;

    // Setter methods
    void setId(const std::string& newId);
    void setFullName(const std::string& newFullName);
    void setBirthday(const std::string& newBirthday);
    void setPhone(const std::string& newPhone);
    void setEmail(const std::string& newEmail);
    void setEmployeeType(uint newEmployeeType);
    void setCertificates(const std::list<Certificate>& certificates);

    // Pure virtual method
    virtual void showInfo() const = 0;
    virtual void updateInfo() = 0;
    void addCertificate(const Certificate& certificate);
    void removeCertificate(const std::string& certificateId);
};

#endif
