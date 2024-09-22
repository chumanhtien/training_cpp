#include <iostream>
#include <memory>
#include "../inc/Town.h"
#include <limits>
#include <set>

using namespace std;

int main() {
    Town town;
    set<string> identityNumbers;
    set<uint> houseNumbers;

    uint n;
    cout << "Enter the number of families: ";
    cin >> n;
    if (cin.fail()) {
        cerr << "Invalid input!. Please input the number\n";
        cin.clear(); // xóa cờ lỗi của cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
    }

    for (uint i = 0; i < n; ++i) {
        uint houseNumber;
        cout << "Enter house number for family " << (i + 1) << ": ";
        cin >> houseNumber;
        if (cin.fail()) {
            cerr << "Invalid input!. Please input the number\n";
            cin.clear(); // xóa cờ lỗi của cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
            i--;
            continue; // yêu cầu nhập lại
        }
        if (houseNumbers.find(houseNumber) != houseNumbers.end()) {
            cerr << "Duplicate house number! Please enter a unique identity number.\n";
            i--;
            continue; // yêu cầu nhập lại
        } else {
            // Nếu chưa tồn tại thì thêm vào tập hợp và thoát vòng lặp
            houseNumbers.insert(houseNumber);
        }

        uint memberCount;
        cout << "Enter number of members in this family: ";
        cin >> memberCount;
        if (cin.fail()) {
            cerr << "Invalid input!. Please input the number\n";
            cin.clear(); // xóa cờ lỗi của cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
            i--;
            continue; // yêu cầu nhập lại
        }

        unique_ptr<Family> family = make_unique<Family>(memberCount, houseNumber);

        for (uint j = 0; j < memberCount; ++j) {
            string name, career, identityNumber;
            uint age;

            cout << "Enter name of member " << (j + 1) << ": ";
            cin.ignore(); // Clear the input buffer
            getline(cin, name);

            cout << "Enter age: ";
            cin >> age;
            if (cin.fail()) {
                cerr << "Invalid input!. Please input the number\n";
                cin.clear(); // xóa cờ lỗi của cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                j--;
                continue; // yêu cầu nhập lại
            }

            cout << "Enter career: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, career);

            cout << "Enter identity number: ";
            getline(cin, identityNumber);
            if (identityNumbers.find(identityNumber) != identityNumbers.end()) {
                cerr << "Duplicate identity number! Please enter a unique identity number.\n";
                j--;
                continue;
            } else {
                // Nếu chưa tồn tại thì thêm vào tập hợp và thoát vòng lặp
                identityNumbers.insert(identityNumber);
            }

            family->addMember(make_unique<Person>(name, age, career, identityNumber));
        }

        town.addFamily(move(family));
    }

    cout << "\n--- Families in the Town ---\n";
    town.displayFamilies();

    return 0;
}
