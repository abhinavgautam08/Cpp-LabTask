// Create a custom exception class InvalidInputException in C++ to handle 
// invalid inputs. Implement a function that takes user input and throws an 
// InvalidInputException if the input is not valid. Use try, catch, and throw 
// blocks to handle the exception and display an appropriate error message. 

#include <iostream>
#include <stdexcept>
#include <string>

class InvalidInputException : public std::exception {
private:
    std::string message;
public:
    InvalidInputException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void validateInput() {
    int value;
    std::cout << "Enter a positive no: ";
    std::cin >> value;

    if (std::cin.fail() || value <= 0) {
        throw InvalidInputException("Error: Input must be a positive no.");
    }
    std::cout << "Valid input received: " << value << std::endl;
}

int main() {
    try {
        validateInput();
    } catch (const InvalidInputException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    return 0;
}
