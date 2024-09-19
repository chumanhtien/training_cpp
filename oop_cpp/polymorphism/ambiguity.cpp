#include<iostream>

class A {
public:
    int x;

    virtual void show() { std::cout << "A's show" << std::endl; }
    A() {
        std::cout << "A's constructor is called\n";
    }
    ~A() {
        std::cout << "A's destructor is called\n";
    }
};

class B {
public:
    int x;

    virtual void show() { std::cout << "B's show" << std::endl; }
    B() {
        std::cout << "B's constructor is called\n";
    }
    B(int x): x{x} {}
    ~B() {
        std::cout << "B's destructor is called\n";
    }
};

class C : public B, public A {
    void show() override {
        std::cout << "C's show\n";
    }
};

int main() {
    C obj;
    // Truy cập biến x của lớp A hay B?
    // obj.x = 10;  // Lỗi: ambiguity issue (không rõ x của A hay B)

    // Bạn cần chỉ định rõ lớp cha nào bạn muốn truy cập biến x
    obj.A::x = 20;  // Gán cho biến x của lớp A
    obj.B::x = 30;  // Gán cho biến x của lớp B

    std::cout << "A's x: " << obj.A::x << std::endl;  // 20
    std::cout << "B's x: " << obj.B::x << std::endl;  // 30

    return 0;
}
