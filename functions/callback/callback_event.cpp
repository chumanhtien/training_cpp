#include <iostream>
#include <functional>
#include <vector>
using namespace std;
// Lớp Button mô phỏng một nút trong giao diện người dùng
class Button {
public:
    // Callback lưu trữ hàm sẽ được gọi khi nhấn nút
    function<void()> onClick;

    // Phương thức để gán callback
    void setOnClick(function<void()> callback) {
        onClick = callback;
    }

    // Phương thức giả lập việc nhấn nút
    void click() {
        if (onClick) {
            onClick();  // Gọi callback khi nút được nhấn
        }
    }
};

// Một số hàm callback cụ thể
void showMessage() {
    cout << "Button clicked! Showing message..." << endl;
}

void performCalculation() {
    cout << "Button clicked! Performing calculation..." << endl;
    // Giả lập một phép tính
    int result = 5 + 10;
    cout << "Result: " << result << endl;
}

int main() {
    // Tạo một đối tượng Button
    Button myButton;

    // Gán hàm showMessage() làm callback khi nhấn nút
    myButton.setOnClick(showMessage);

    // Giả lập việc nhấn nút
    myButton.click();

    // Gán một hàm callback khác
    myButton.setOnClick(performCalculation);

    // Giả lập việc nhấn nút lần nữa
    myButton.click();

    return 0;
}
