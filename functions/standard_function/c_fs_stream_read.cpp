#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Tạo một đối tượng fstream và mở file để đọc (read mode)
    fstream file;
    file.open("example.txt", ios::in);

    if (file.is_open()) {
        string line;

        // Đọc từng dòng từ file
        while (getline(file, line)) {
            cout << line << endl;
        }

        // Đóng file
        file.close();
    } else {
        cout << "Failed to open the file." << endl;
    }

    return 0;
}
