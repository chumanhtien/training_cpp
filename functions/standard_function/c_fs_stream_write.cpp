#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Tạo một đối tượng fstream và mở file để ghi (write mode)
    fstream file;
    file.open("example.txt", ios::out);

    if (file.is_open()) {
        // Ghi dữ liệu vào file
        file << "Hello, World!" << endl;
        file << "This is a test file." << endl;

        // Đóng file
        file.close();
        cout << "Data written to file successfully." << endl;
    } else {
        cout << "Failed to open the file." << endl;
    }

    return 0;
}
