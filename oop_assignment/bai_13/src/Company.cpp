#include "../inc/Company.h"
#include "../inc/Validator.h" // Bao gồm Validator
#include "../inc/Experience.h"
#include "../inc/Fresher.h"
#include "../inc/Intern.h"

void Company::addEmployee(std::shared_ptr<Employee> employee) {
    
    if (employees.find(employee->getId()) != employees.end()) {
        std::cout << "Error: Employee with ID " << employee->getId() << " already exists!" << std::endl;
        return; // Không thêm nếu đã tồn tại
    }

    employees[employee->getId()] = employee;
    std::cout << "Employee added successfully!" << std::endl;
}

void Company::updateEmployee(const std::string& id) {
    auto it = employees.find(id);
    if (it == employees.end()) {
        std::cout << "Employee not found!" << std::endl;
        return;
    }

    std::shared_ptr<Employee> employee = it->second;

    try {
        // Hiển thị thông tin của nhân viên hiện tại trước khi cập nhật
        std::cout << "Current Employee Information: " << std::endl;
        employee->showInfo();

        // Gọi trực tiếp updateInfo() từ con trỏ Employee*
        employee->updateInfo();

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void Company::removeEmployee(const std::string& id) {
    auto it = employees.find(id);
    if (it != employees.end()) {
        employees.erase(it);
        std::cout << "Employee removed successfully!" << std::endl;
    } else {
        std::cout << "Employee not found!" << std::endl;
    }
}

void Company::findAllInterns() const {
    for (const auto& pair : employees) {
        if (dynamic_cast<Intern*>(pair.second.get())) {
            pair.second->showInfo();
        }
    }
}

void Company::findAllExperience() const {
    for (const auto& pair : employees) {
        if (dynamic_cast<Experience*>(pair.second.get())) {
            pair.second->showInfo();
        }
    }
}

void Company::findAllFreshers() const {
    for (const auto& pair : employees) {
        if (dynamic_cast<Fresher*>(pair.second.get())) {
            pair.second->showInfo();
        }
    }
}
