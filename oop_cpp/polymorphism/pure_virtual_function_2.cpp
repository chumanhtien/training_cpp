#include <iostream>
#include <string>

// Lớp trừu tượng cơ sở
class Shape {
public:
    virtual ~Shape() = default; // Destructor ảo
    virtual void draw() const = 0;      // Phương thức thuần ảo
    virtual double area() const = 0;    // Phương thức thuần ảo

    void setColor(const std::string& color) { // Phương thức không thuần ảo
        this->color = color;
    }
    
    std::string getColor() const { // Phương thức không thuần ảo
        return color;
    }

private:
    std::string color; // Dữ liệu thành viên
};

// Interface
class IShape {
public:
    virtual ~IShape() = default; // Destructor ảo
    virtual void render() const = 0;  // Phương thức thuần ảo
};

// Lớp kế thừa từ Shape và triển khai IShape
class Circle : public Shape, public IShape {
public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        std::cout << "Drawing Circle with color: " << getColor() << std::endl;
    }
    double area() const override {
        return 3.14 * radius * radius;
    }
    void render() const override {
        draw();
    }
private:
    double radius;
};
// Lớp kế thừa từ Shape và triển khai IShape
class Rectangle : public Shape, public IShape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    void draw() const override {    
        std::cout << "Drawing Rectangle with color: " << getColor() << std::endl;
    }
    double area() const override {
        return width * height;
    }
    void render() const override {
        draw();
    }
private:
    double width;
    double height;
};

int main() {
    Circle circle(5.0);
    circle.setColor("Red");
    circle.render(); // Sử dụng phương thức render từ IShape
    std::cout << "Circle area: " << circle.area() << std::endl;

    Rectangle rectangle(4.0, 6.0);
    rectangle.setColor("Blue");
    rectangle.render(); // Sử dụng phương thức render từ IShape
    std::cout << "Rectangle area: " << rectangle.area() << std::endl;

    return 0;
}
