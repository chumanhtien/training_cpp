#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show() method called" << endl;
    }
};

class Derived : public Base {
public:
    virtual void show() {
        cout << "Derived class show() method called" << endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = new Derived();
    // Derived derivedObj;
    
    // basePtr = &derivedObj;

    // Gọi phương thức thông qua con trỏ lớp cơ sở
    basePtr->show();  // Output: "Base class show() method called"
    derivedPtr->show();
    
    return 0;
}
