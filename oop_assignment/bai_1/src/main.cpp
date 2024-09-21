#include <iostream>
#include <string>
#include "../inc/Engineer.h"
#include "../inc/Officer.h"
#include "../inc/Staff.h"
#include "../inc/Worker.h"
#include "../inc/ManagerOfficer.h"
#include <limits>

using namespace std;

int main() {
    cout << "Hello World\n";
    ManagerOfficer managerOfficer;



    while (true) {
        cout << "Application Manager Officer\n";
        cout << "Enter '1' to add an officer\n";
        cout << "Enter '2' to search officer by name\n";
        cout << "Enter '3' to print list officer\n";
        cout << "Enter '4' to exit\n";

        string line;
        getline(cin, line);

        if (line == "1") {
            cout << "Enter 'a' to insert Engineer\n";
            cout << "Enter 'b' to insert Worker\n";
            cout << "Enter 'c' to insert Staff\n";
            cout << "Enter 'd' to return main menu\n";
            string type;
            getline(cin, type);

            if (type == "a") {
                string name;
                uint age;
                uint gender;
                string address;
                string branch;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                if (std::cin.fail()) {
                    std::cerr << "Invalid input! Please enter a number.\n";
                    std::cin.clear(); // xóa cờ lỗi của cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                    continue; // yêu cầu nhập lại
                }
                cout << "Enter gender (press '0' for 'Male'; press '1' for 'Female'; press '2' for 'Other'): ";
                cin >> gender;
                cin.ignore();
                // Kiểm tra nếu nhập không phải số
                if (std::cin.fail()) {
                    std::cerr << "Invalid input! Please enter a number.\n";
                    std::cin.clear(); // xóa cờ lỗi của cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                    continue; // yêu cầu nhập lại
                }
                if ((gender != 0 && gender != 1 && gender != 2)) {
                    cout << "Invalid gender! Press '0' or '1' or '2'\n";
                    continue;
                }
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter branch: ";
                getline(cin, branch);

                Officer* engineer = new Engineer(name, age, gender, address, branch);
                managerOfficer.add(engineer);
                cout << engineer->toString() << endl;
            } else if (type == "b") {
                string name;
                uint age;
                uint gender;
                string address;
                string branch;
                uint level;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                if (std::cin.fail()) {
                    std::cerr << "Invalid input! Please enter a number.\n";
                    std::cin.clear(); // xóa cờ lỗi của cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                    continue; // yêu cầu nhập lại
                }
                cout << "Enter gender (press '0' for 'Male'; press '1' for 'Female'; press '2' for 'Other'): ";
                cin >> gender;
                cin.ignore();
                // Kiểm tra nếu nhập không phải số
                if (std::cin.fail()) {
                    std::cerr << "Invalid input! Please enter a number.\n";
                    std::cin.clear(); // xóa cờ lỗi của cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                    continue; // yêu cầu nhập lại
                }
                if ((gender != 0 && gender != 1 && gender != 2)) {
                    cout << "Invalid gender! Press '0' or '1' or '2'\n";
                    continue;
                }
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter level: ";
                cin >> level;
                if (std::cin.fail()) {
                    std::cerr << "Invalid input! Please enter a number.\n";
                    std::cin.clear(); // xóa cờ lỗi của cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                    continue; // yêu cầu nhập lại
                }

                if (level < 1 || level > 10) {
                    cerr << "Invalid level! Level must be between 1 and 10.\n";
                    continue; // Không thêm vào danh sách nếu level không hợp lệ
                }
                cin.ignore();

                Officer* worker = new Worker(name, age, gender, address, level);
                managerOfficer.add(worker);
                cout << worker->toString() << endl;
            } else if (type == "c") {
                string name;
                uint age;
                uint gender;
                string address;
                string branch;
                string task;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                if (std::cin.fail()) {
                    std::cerr << "Invalid input! Please enter a number.\n";
                    std::cin.clear(); // xóa cờ lỗi của cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                    continue; // yêu cầu nhập lại
                }
                cout << "Enter gender (press '0' for 'Male'; press '1' for 'Female'; press '2' for 'Other'): ";
                cin >> gender;
                cin.ignore();
                // Kiểm tra nếu nhập không phải số
                if (std::cin.fail()) {
                    std::cerr << "Invalid input! Please enter a number.\n";
                    std::cin.clear(); // xóa cờ lỗi của cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                    continue; // yêu cầu nhập lại
                }
                if ((gender != 0 && gender != 1 && gender != 2)) {
                    cout << "Invalid gender! Press '0' or '1' or '2'\n";
                    continue;
                }
                cout << "Enter task: ";
                getline(cin, task);

                Officer* staff = new Staff(name, age, gender, address, task);
                managerOfficer.add(staff);
                cout << staff->toString() << endl;
            } else if (type == "d") {
                break;  // Quay lại menu chính
            } else {
                cout << "Invalid" << endl;
                continue;
            }
        } else if (line == "2") {
            cout << "Enter name to search: ";
            string name;
            getline(cin, name);
            auto result = managerOfficer.searchByName(name);
            Officer** foundOfficers = result.first; // Mảng officer tìm thấy
            uint foundCount = result.second; // Số lượng officer tìm thấy

            for (uint i = 0; i < foundCount; ++i) {
                cout << foundOfficers[i]->toString() << endl; // In thông tin officer tìm thấy
            }

            delete[] foundOfficers; // Giải phóng bộ nhớ
        } else if (line == "3") {
            cout << "Print list infor of all officers: \n";
            managerOfficer.showListInfor();
        } else if (line == "4") {
            break;  // Thoát chương trình
        } else {
            cout << "Invalid" << endl;
        }
    }
    return 0;
} 