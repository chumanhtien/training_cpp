#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    // 1. exit() - Thoát chương trình
    cout << "Exit example" << endl;
    if (false) {
        exit(0); // Kết thúc chương trình ngay lập tức
    }

    // 2. system() - Thực hiện lệnh hệ thống
    cout << "System example" << endl;
    // system("ls"); // Chạy lệnh "ls" trên hệ thống Unix/Linux (comment out vì có thể không chạy được trên mọi hệ thống)

    // 3. abs() - Trả về giá trị tuyệt đối
    int num = -10;
    cout << "Absolute value of " << num << " is: " << abs(num) << endl;

    // 4. atof() - Chuyển đổi chuỗi thành số thực (double)
    const char* str = "3.14159";
    double pi = atof(str);
    cout << "String \"" << str << "\" to double is: " << pi << endl;

    // 5. atoi() - Chuyển đổi chuỗi thành số nguyên (int)
    const char* strInt = "42";
    int intValue = atoi(strInt);
    cout << "String \"" << strInt << "\" to int is: " << intValue << endl;

    // 6. atol() - Chuyển đổi chuỗi thành số nguyên dài (long)
    const char* strLong = "1234567890";
    long longValue = atol(strLong);
    cout << "String \"" << strLong << "\" to long is: " << longValue << endl;

    // 7. atof(), atoi(), atol() cũng có các phiên bản nâng cao là strtod(), strtol(), strtoul() 
    // để xử lý chuyển đổi với phạm vi lớn hơn và độ chính xác cao hơn.

    // 8. rand() & srand() - Tạo số ngẫu nhiên
    srand(time(0)); // Khởi tạo seed để rand() cho kết quả ngẫu nhiên mỗi lần chạy
    int randomNum = rand(); // Tạo số ngẫu nhiên
    cout << "Random number: " << randomNum << endl;

    // 9. calloc() - Cấp phát bộ nhớ động và khởi tạo các phần tử về 0
    int* arr = (int*)calloc(5, sizeof(int)); // Cấp phát bộ nhớ cho mảng 5 phần tử, khởi tạo về 0
    if (arr != nullptr) {
        cout << "Memory allocated and initialized using calloc: ";
        for (int i = 0; i < 5; ++i) {
            cout << arr[i] << " "; // In ra mảng
        }
        cout << endl;
        free(arr); // Giải phóng bộ nhớ
    }

    // 10. malloc() - Cấp phát bộ nhớ động nhưng không khởi tạo
    arr = (int*)malloc(5 * sizeof(int)); // Cấp phát bộ nhớ cho mảng 5 phần tử
    if (arr != nullptr) {
        cout << "Memory allocated using malloc: ";
        for (int i = 0; i < 5; ++i) {
            arr[i] = i * 10; // Khởi tạo thủ công
            cout << arr[i] << " "; // In ra mảng
        }
        cout << endl;
        free(arr); // Giải phóng bộ nhớ
    }

    // 11. realloc() - Thay đổi kích thước bộ nhớ đã cấp phát
    arr = (int*)malloc(3 * sizeof(int)); // Cấp phát bộ nhớ cho mảng 3 phần tử
    if (arr != nullptr) {
        arr[0] = 1; arr[1] = 2; arr[2] = 3;
        cout << "Before realloc: ";
        for (int i = 0; i < 3; ++i) {
            cout << arr[i] << " "; // In ra mảng
        }
        cout << endl;

        arr = (int*)realloc(arr, 5 * sizeof(int)); // Tăng kích thước mảng lên 5 phần tử
        arr[3] = 4; arr[4] = 5; // Khởi tạo các phần tử mới
        cout << "After realloc: ";
        for (int i = 0; i < 5; ++i) {
            cout << arr[i] << " "; // In ra mảng
        }
        cout << endl;

        free(arr); // Giải phóng bộ nhớ
    }
    cout << "Done" << endl;
    return 0;
}
