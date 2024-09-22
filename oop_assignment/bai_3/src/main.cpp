#include "../inc/CandidateManager.h"
#include "../inc/CandidateA.h"
#include "../inc/CandidateB.h"
#include "../inc/CandidateC.h"
#include <limits>
using namespace std;

int main() {
    CandidateManager candidateManager;
    int choice;
    candidateManager.add(std::make_shared<CandidateA>(1, "Nguyen Van A", "Hanoi", 1));
    candidateManager.add(std::make_shared<CandidateB>(2, "Nguyen Van B", "Bacninh", 2));
    candidateManager.add(std::make_shared<CandidateC>(3, "Nguyen Van C", "Namdinh", 3));

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Press '1' to Add candidate\n";
        cout << "2. Press '2' Show list candidates\n";
        cout << "3. Press '3' Find candidate with Id\n";
        cout << "4. Press '4' Exit\n";
        cout << "Choose option: ";
        cin >> choice;
        if (cin.fail()) {
            cerr << "Invalid input!. Choose Valid option\n";
            cin.clear(); // xóa cờ lỗi của cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
            continue; // yêu cầu nhập lại
        }

        if (choice == 4) break;

        uint id;
        string name, address;
        uint priority;
        uint examBlock;

        switch (choice) {
            case 1: {
                cout << "Enter Id: ";
                cin >> id;
                cin.ignore();
                if (cin.fail()) {
                    cerr << "Invalid input!.\n";
                    cin.clear(); // xóa cờ lỗi của cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                    continue; // yêu cầu nhập lại
                }
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter priority: ";
                cin >> priority;
                if (cin.fail()) {
                    cerr << "Invalid input!. Please input the number\n";
                    cin.clear(); // xóa cờ lỗi của cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                    continue; // yêu cầu nhập lại
                }
                cout << "Choose (exam block Press: '1' - A, '2' - B, '3' - C): ";
                cin >> examBlock;
                if (cin.fail()) {
                    cerr << "Invalid input!. Please input the number\n";
                    cin.clear(); // xóa cờ lỗi của cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua các ký tự không hợp lệ trong input buffer
                    continue; // yêu cầu nhập lại
                }

                if (examBlock == 1) {
                    candidateManager.add(make_shared<CandidateA>(id, name, address, priority));
                } else if (examBlock == 2) {
                    candidateManager.add(make_shared<CandidateB>(id, name, address, priority));
                } else if (examBlock == 3) {
                    candidateManager.add(make_shared<CandidateC>(id, name, address, priority));
                } else {
                    cout << "Invalid Exam block!\n";
                }
                continue;
            }

            case 2: {
                cout << "List candidates here:\n";
                candidateManager.showListCandidate();
                continue;
            }

            case 3: {
                cout << "Enter Id to find: ";
                cin >> id;
                shared_ptr<Candidate> candidate = candidateManager.findCandidateWithId(id);
                if (candidate != nullptr) {
                    cout << candidate->toString();
                }
                continue;
            }

            case 4: {
                cout << "Exit program \n";
                break;
            }

            default: {
                cout << "Invalid option!\n";
                continue;
            }
        }
    }
}