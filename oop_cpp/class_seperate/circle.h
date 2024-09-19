#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <cassert>

using namespace std;

// Class Definition
class Circle {
    private: 
        double radius;
    public: 
        Circle(double radius); // Parameter constructor
        Circle(); // Default construct
        Circle(const Circle& circle); // Copy constructor
        ~Circle(); // Destructor

        void setRadius(double radius); // Mutator function
        double getRadius() const; // Accessor function
        double getArea() const; // Accessor function
        double getPerimeter() const; // Accessor function
};
#endif