#include <iostream>

class Shape {
public:
    // Hàm ảo thuần túy
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Square" << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw();  // Output: Drawing Circle
    shape2->draw();  // Output: Drawing Square

    delete shape1;
    delete shape2;
}
