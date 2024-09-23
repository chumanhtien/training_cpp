#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <unordered_map>
#include <memory> // Thêm thư viện cho smart pointer
#include "Employee.h"
#include "Exception.h"

class Company {
private:
    // Sử dụng std::shared_ptr thay vì con trỏ thô cho nhân viên
    std::unordered_map<std::string, std::shared_ptr<Employee>> employees;

public:
    // Destructor không cần thiết nếu dùng smart pointers, vì smart pointers sẽ tự giải phóng bộ nhớ
    ~Company() = default;

    void addEmployee(std::shared_ptr<Employee> employee);
    void updateEmployee(const std::string& id);
    void removeEmployee(const std::string& id);
    
    void findAllInterns() const;
    void findAllExperience() const;
    void findAllFreshers() const;

    // Hàm kiểm tra tính hợp lệ
    void validateBirthday(const std::string& birthday);
    void validatePhone(const std::string& phone);
    void validateEmail(const std::string& email);
    void validateFullName(const std::string& fullName);
};

#endif
