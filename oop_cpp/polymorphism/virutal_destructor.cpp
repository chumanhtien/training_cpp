#include <iostream>

class Base {
public:
    virtual ~Base() {  // Virtual Destructor
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {  // Override Destructor
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Destructor of Derived is called first, then Destructor of Base
    return 0;
}
