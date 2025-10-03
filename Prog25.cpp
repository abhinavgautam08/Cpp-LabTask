//Implement a template-based stack class in C++ that supports basic stack 
//operations such as push, pop, top, and isEmpty. Ensure the class works with 
//different data types and includes appropriate exception handling for stack 
//underflow and overflow.

#include <iostream>
#include <stdexcept>

template <typename T, int Size>
class Stack {
private:
    T arr[Size];
    int topIndex;

public:
    Stack() : topIndex(-1) {}
    void push(const T& value) {
        if (topIndex >= Size - 1) {
            throw std::overflow_error("Stack Overflow");
        }
        arr[++topIndex] = value;
    }
    void pop() {
        if (topIndex < 0) {
            throw std::underflow_error("Stack Underflow");
        }
        --topIndex;
    }
    T top() const {
        if (topIndex < 0) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[topIndex];
    }
    bool isEmpty() const {
        return topIndex < 0;
    }
};
int main() {
    try {
        Stack<int, 5> s;
        s.push(10);
        s.push(20);
        std::cout << "Top element: " << s.top() << std::endl;
        s.pop();
        std::cout << "Top element after pop: " << s.top() << std::endl;
        s.pop();
        s.pop(); 
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
