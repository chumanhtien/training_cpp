#include<iostream>

class Base {
public:
    virtual void print() {
        std::cout << "Hello World from Base\n";
    }
    virtual void show() {
        std::cout << "Base show" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() {
        std::cout << "Hello World from Devired\n";
    }
    void show(int x) {  // Khác tham số, không ghi đè đúng
        std::cout << "Derived show with int" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->print(); // Vẫn gọi của Derived, vẫn override mà không cần từ khóa
    b->show(); // Vẫn gọi của Base, không gọi của Devired, không cảnh báo lỗi
    return 0;
}
