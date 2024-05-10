#include <iostream>
#include <cmath> // For math functions like PI

using namespace std;

// Base class Shape
class Shape {
public:
    // Virtual function for calculating area (to be overridden by derived classes)
    virtual float calculateArea() = 0; // Pure virtual function

    // Virtual destructor (important for polymorphic behavior)
   virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
private:
    float radius;

public:
    // Constructor
    Circle(float r) : radius(r) {}

    // Override calculateArea() method
    float calculateArea() override {
        return M_PI * radius * radius; // Area = π * r^2
    }
};

// Derived class Square
class Square : public Shape {
private:
    float side;

public:
    // Constructor
    Square(float s) : side(s) {}

    // Override calculateArea() method
    float calculateArea() override {
        return side * side; // Area = side * side
    }
};

// Derived class Triangle
class Triangle : public Shape {
private:
    float base, height;

public:
    // Constructor
    Triangle(float b, float h) : base(b), height(h) {}

    // Override calculateArea() method
    float calculateArea() override {
        return 0.5 * base * height; // Area = 0.5 * base * height
    }
};

int main() {
    // Creating objects of different shapes
    Circle circle(5.0);
    Square square(4.0);
    Triangle triangle(3.0, 6.0);

    // Calculating and displaying areas
    cout << "Area of Circle: " << circle.calculateArea() << endl;
    cout << "Area of Square: " << square.calculateArea() << endl;
    cout << "Area of Triangle: " << triangle.calculateArea() << endl;

    return 0;
}