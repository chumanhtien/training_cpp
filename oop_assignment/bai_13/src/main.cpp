#include <iostream>
#include <string>
#include "../inc/Company.h"
#include "../inc/Experience.h"
#include "../inc/Fresher.h"
#include "../inc/Intern.h"

int main() {
    Company company;
    int choice;
    // Add initial employees with certificates
    std::list<Certificate> certsForE001 = {
        Certificate("C001", "Chứng chỉ Lập trình C++", "Xuất sắc", "2020-01-01"),
        Certificate("C002", "Chứng chỉ Quản lý dự án", "Giỏi", "2021-02-01")
    };
    std::list<Certificate> certsForE002 = {
        Certificate("C003", "Chứng chỉ Lập trình Java", "Xuất sắc", "2019-03-01"),
        Certificate("C004", "Chứng chỉ Kiến trúc phần mềm", "Giỏi", "2022-04-01")
    };
    std::list<Certificate> certsForF001 = {
        Certificate("C005", "Chứng chỉ Kỹ sư phần mềm", "Khá", "2023-05-01")
    };
    std::list<Certificate> certsForF002 = {
        Certificate("C006", "Chứng chỉ Lập trình Python", "Xuất sắc", "2022-06-01")
    };
    std::list<Certificate> certsForI001 = {
        Certificate("C007", "Chứng chỉ Thực tập sinh CNTT", "Khá", "2023-07-01")
    };
    std::list<Certificate> certsForI002 = {
        Certificate("C008", "Chứng chỉ Kinh tế", "Giỏi", "2023-08-01")
    };

    // Add employees with certificates
    auto exp1 = std::make_shared<Experience>("E001", "Nguyen Van A", "1990-01-01", "0123456789", "vana@example.com", 5, "C++");
    exp1->setCertificates(certsForE001);
    company.addEmployee(exp1);

    auto exp2 = std::make_shared<Experience>("E002", "Tran Thi B", "1988-02-02", "0987654321", "tranb@example.com", 3, "Java");
    exp2->setCertificates(certsForE002);
    company.addEmployee(exp2);

    auto fresher1 = std::make_shared<Fresher>("F001", "Le Van C", "2000-03-03", "0123456788", "vanc@example.com", "2022-06-15", "Xuất sắc", "Đại học B");
    fresher1->setCertificates(certsForF001);
    company.addEmployee(fresher1);

    auto fresher2 = std::make_shared<Fresher>("F002", "Pham Thi D", "2001-04-04", "0987654310", "trand@example.com", "2023-06-15", "Khá", "Đại học A");
    fresher2->setCertificates(certsForF002);
    company.addEmployee(fresher2);

    auto intern1 = std::make_shared<Intern>("I001", "Hoang Van E", "2002-05-05", "0123456790", "vane@example.com", "CNTT", "Học kỳ 2", "Đại học C");
    intern1->setCertificates(certsForI001);
    company.addEmployee(intern1);

    auto intern2 = std::make_shared<Intern>("I002", "Nguyen Thi F", "2003-06-06", "0987654322", "fnguyen@example.com", "Kinh tế", "Học kỳ 1", "Đại học D");
    intern2->setCertificates(certsForI002);
    company.addEmployee(intern2);


    do {
        std::cout << "\n========== MENU ==========\n";
        std::cout << "1. Thêm nhân viên\n";
        std::cout << "2. Sửa thông tin nhân viên\n";
        std::cout << "3. Xóa nhân viên theo ID\n";
        std::cout << "4. Tìm tất cả nhân viên Intern\n";
        std::cout << "5. Tìm tất cả nhân viên Experience\n";
        std::cout << "6. Tìm tất cả nhân viên Fresher\n";
        std::cout << "7. Thoát\n";
        std::cout << "===========================\n";
        std::cout << "Lựa chọn của bạn: ";
        std::cin >> choice;

        std::string id, fullName, birthday, phone, email, skill, graduationDate, graduationRank, education, major, semester, university;
        uint yearsOfExperience;
        int employeeType;

        switch (choice) {
        case 1:
            std::cout << "Nhập loại nhân viên (1: Experience, 2: Fresher, 3: Intern): ";
            std::cin >> employeeType;

            std::cout << "Nhập ID: ";
            std::cin >> id;
            std::cout << "Nhập họ tên: ";
            std::cin.ignore();
            std::getline(std::cin, fullName);
            std::cout << "Nhập ngày sinh: ";
            std::cin >> birthday;
            std::cout << "Nhập số điện thoại: ";
            std::cin >> phone;
            std::cout << "Nhập email: ";
            std::cin >> email;

            if (employeeType == 1) {
                std::cout << "Nhập số năm kinh nghiệm: ";
                std::cin >> yearsOfExperience;
                std::cout << "Nhập kỹ năng: ";
                std::cin.ignore();
                std::getline(std::cin, skill);
                std::shared_ptr<Employee> experienceEmployee = std::make_shared<Experience>(id, fullName, birthday, phone, email, yearsOfExperience, skill);
                company.addEmployee(experienceEmployee);
            } else if (employeeType == 2) {
                std::cout << "Nhập ngày tốt nghiệp: ";
                std::cin >> graduationDate;
                std::cout << "Nhập xếp hạng tốt nghiệp: ";
                std::cin >> graduationRank;
                std::cout << "Nhập tên trường đại học: ";
                std::cin.ignore();
                std::getline(std::cin, education);
                std::shared_ptr<Employee> fresherEmployee = std::make_shared<Fresher>(id, fullName, birthday, phone, email, graduationDate, graduationRank, education);
                company.addEmployee(fresherEmployee);
            } else if (employeeType == 3) {
                std::cout << "Nhập chuyên ngành: ";
                std::cin.ignore();
                std::getline(std::cin, major);
                std::cout << "Nhập học kỳ: ";
                std::cin >> semester;
                std::cout << "Nhập tên trường đại học: ";
                std::cin.ignore();
                std::getline(std::cin, university);
                std::shared_ptr<Employee> internEmployee = std::make_shared<Intern>(id, fullName, birthday, phone, email, major, semester, university);
                company.addEmployee(internEmployee);
            } else {
                std::cout << "Loại nhân viên không hợp lệ!" << std::endl;
            }
            break;

        case 2:
            std::cout << "Nhập ID nhân viên cần sửa: ";
            std::cin >> id;
            company.updateEmployee(id);
            break;

        case 3:
            std::cout << "Nhập ID nhân viên cần xóa: ";
            std::cin >> id;
            company.removeEmployee(id);
            break;

        case 4:
            std::cout << "Danh sách tất cả nhân viên Intern: " << std::endl;
            company.findAllInterns();
            break;

        case 5:
            std::cout << "Danh sách tất cả nhân viên Experience: " << std::endl;
            company.findAllExperience();
            break;

        case 6:
            std::cout << "Danh sách tất cả nhân viên Fresher: " << std::endl;
            company.findAllFreshers();
            break;

        case 7:
            std::cout << "Thoát chương trình." << std::endl;
            break;

        default:
            std::cout << "Lựa chọn không hợp lệ!" << std::endl;
        }
    } while (choice != 7);

    return 0;
}
