// Write a C++ program to evaluate a string expression containing numbers, 
// arithmetic operators (+, -, *, /), and parentheses. Implement a function that 
// parses the expression and computes the result, considering operator 
// precedence and parentheses.

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main(){
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expression);
    stack<int> values;
    stack<char> ops;
    for (size_t i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue;
        if (isdigit(expression[i])){
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;}
            values.push(val);
            i--;
			}
        else if (expression[i] == '(') {
            ops.push(expression[i]);}
        else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                int result = 0;
                if (op == '+') result = val1 + val2;
                else if (op == '-') result = val1 - val2;
                else if (op == '*') result = val1 * val2;
                else if (op == '/') result = val1 / val2;
                values.push(result);}
            ops.pop();
			}
        else {
            while (!ops.empty() && ((ops.top() == '*' || ops.top() == '/') || 
                   ((ops.top() == '+' || ops.top() == '-') && (expression[i] == '+' || expression[i] == '-')))) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                int result = 0;
                if (op == '+') result = val1 + val2;
                else if (op == '-') result = val1 - val2;
                else if (op == '*') result = val1 * val2;
                else if (op == '/') result = val1 / val2;
                values.push(result);
            }
            ops.push(expression[i]);
        }
    }
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        int result = 0;
        if (op == '+') result = val1 + val2;
        else if (op == '-') result = val1 - val2;
        else if (op == '*') result = val1 * val2;
        else if (op == '/') result = val1 / val2;
        values.push(result);
    }
    cout << "Result: " << values.top() << endl;
    return 0;
}
