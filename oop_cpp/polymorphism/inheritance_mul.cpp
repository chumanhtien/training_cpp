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
    // obj.show();  // Lỗi: Không rõ gọi `show()` từ A hay B: error: request for member ‘show’ is ambiguous
    obj.A::show();  // Gọi show() từ lớp A
    obj.B::show();  // Gọi show() từ lớp B
    A* b = new C(); 
    B* c = new C();
    b->show();
    c->show();
    delete b;
    delete c;
}