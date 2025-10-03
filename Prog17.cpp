// Create a class ComplexNumber to represent complex numbers. Implement 
// operator overloading for +, -, *, and / operators to perform arithmetic 
// operations on complex numbers. Use inheritance to extend the class with 
// additional functionality for polar representation.

#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber {
protected:
    double real; 
    double imag; 
public:
    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}
    double getReal() const { return real; }
    double getImag() const { return imag; }
    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(real + other.real, imag + other.imag);
    }
    ComplexNumber operator-(const ComplexNumber& other) {
        return ComplexNumber(real - other.real, imag - other.imag);
    }
    ComplexNumber operator*(const ComplexNumber& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real; 
        return ComplexNumber(r, i);
    }
    ComplexNumber operator/(const ComplexNumber& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return ComplexNumber(r, i);
    }
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};
class PolarComplexNumber : public ComplexNumber {
public:
    PolarComplexNumber(double magnitude = 0, double angle = 0) {
        real = magnitude * cos(angle); 
        imag = magnitude * sin(angle);
    }
    void displayPolar() const {
        double magnitude = sqrt(real * real + imag * imag);
        double angle = atan2(imag, real);
        cout << "Polar Representation -> Magnitude: " << magnitude << ", Angle: " << angle << " radians" << endl;
    }
    void setPolar(double magnitude, double angle) {
        real = magnitude * cos(angle);
        imag = magnitude * sin(angle);
    }
};

int main() {
    ComplexNumber num1(3, 4);
    ComplexNumber num2(1, 2);
    cout << "Complex Number 1: ";
    num1.display();
    cout << "Complex Number 2: ";
    num2.display();
    ComplexNumber result;

    result = num1 + num2;
    cout << "Addition Result: ";
    result.display();
    
    result = num1 - num2;
    cout << "Subtraction Result: ";
    result.display();
    
    result = num1 * num2;
    cout << "Multiplication Result: ";
    result.display();
    
    result = num1 / num2;
    cout << "Division Result: ";
    result.display();
    
    PolarComplexNumber polarNum(5, 0.9273); 
    cout << "\nPolar Complex Number: ";
    polarNum.displayPolar();
   
    ComplexNumber rectForm = polarNum;
    cout << "Converted to Rectangular Form: ";
    rectForm.display();

    return 0;
}
