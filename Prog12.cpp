// Create an abstract class Shape with a pure virtual function calculateArea(), 
// deriving classes Circle, Rectangle, and Triangle each with attributes relevant 
// to their shapes, implementing default and parameterized constructors, 
// methods to calculate and display the area of each shape, and an array of 
// Shape pointers to store different shapes and calculate their areas.

#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle() : radius(0) {}

    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        std::cout << "Circle with radius " << radius << " has area: " << calculateArea() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle() : length(0), width(0) {}

    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override {
        return length * width;
    }

    void display() const override {
        std::cout << "Rectangle with length " << length << " and width " << width << " has area: " << calculateArea() << std::endl;
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle() : base(0), height(0) {}

    Triangle(double b, double h) : base(b), height(h) {}

    double calculateArea() const override {
        return 0.5 * base * height;
    }

    void display() const override {
        std::cout << "Triangle with base " << base << " and height " << height << " has area: " << calculateArea() << std::endl;
    }
};

int main() {
    Shape* shapes[3];

    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);
    shapes[2] = new Triangle(3, 8);

    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
    }

    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}
