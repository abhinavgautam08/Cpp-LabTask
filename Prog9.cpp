//Create a class Rational to represent rational numbers with attributes 
//numerator and denominator, implementing default, parameterized, and copy 
//constructors, methods to add, subtract, multiply, and divide rational 
//numbers, overloading the << and >> operators for input and output, and a 
//friend function to compare two rational numbers.

#include<iostream>
using namespace std;

class Rational{
public:int numerator;int denominator;
    Rational(){numerator = 0;denominator = 1;}
    Rational(int num, int den){
        numerator = num;
        denominator =
		 den;}
    Rational(const Rational &other){
        numerator = other.numerator;
        denominator = other.denominator;}
};
int main(){
    Rational r1, r2;
    cout << "Enter numerator and denominator for 1st rational No: ";
    cin >> r1.numerator >> r1.denominator;
    cout << "Enter numerator and denominator for 2nd rational No.: ";
    cin >> r2.numerator >> r2.denominator;
    cout << "1st Rational No.: " << r1.numerator << "/" << r1.denominator << endl;
    cout << "2nd Rational No.: " << r2.numerator << "/" << r2.denominator << endl;
    return 0;
}
