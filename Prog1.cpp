// Implement a simple calculator in C++ that can perform basic arithmetic 
// operations such as addition, subtraction, multiplication, and division. The 
// program should prompt the user to enter two numbers and an operator, then 
// display the result. Use appropriate data types and control structures to handle 
// the calculations and validate user inputs.

#include<iostream>
using namespace std;

int main(){
    double num1, num2, result;
    char op;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter the second number: ";
    cin >> num2;
    switch (op) {case '+':result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            if (num2 != 0){
                result = num1 / num2;
                cout << "Result: " << result << endl;
            }else {cout << "Error: Division by zero is not allowed." << endl;}
            break;
        default:
            cout << "Error: Invalid operator entered." << endl;}
    return 0;
}