// Create a class Polynomial to represent a polynomial with dynamic memory 
// allocation for coefficients, implementing default, parameterized constructors, 
// and a destructor, methods to add, subtract, and multiply polynomials, 
// overloading the +, -, and * operators for polynomial operations, and friend 
// functions to input and output polynomials. 

#include <iostream>

class Polynomial {
private:
    int degree;
    double* coefficients;

public:
    Polynomial() : degree(0), coefficients(new double[1]{0}) {}

    Polynomial(int deg) : degree(deg), coefficients(new double[deg + 1]{}) {}

    Polynomial(const Polynomial& other) : degree(other.degree), coefficients(new double[other.degree + 1]) {
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = other.coefficients[i];
        }
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] coefficients;
            degree = other.degree;
            coefficients = new double[degree + 1];
            for (int i = 0; i <= degree; i++) {
                coefficients[i] = other.coefficients[i];
            }
        }
        return *this;
    }

    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        Polynomial result(maxDegree);

        for (int i = 0; i <= maxDegree; i++) {
            if (i <= degree) result.coefficients[i] += coefficients[i];
            if (i <= other.degree) result.coefficients[i] += other.coefficients[i];
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        Polynomial result(maxDegree);

        for (int i = 0; i <= maxDegree; i++) {
            if (i <= degree) result.coefficients[i] += coefficients[i];
            if (i <= other.degree) result.coefficients[i] -= other.coefficients[i];
        }
        return result;
    }

    Polynomial operator*(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        Polynomial result(newDegree);

        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                result.coefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return result;
    }

    friend std::istream& operator>>(std::istream& in, Polynomial& poly) {
        std::cout << "Enter coefficients for degree " << poly.degree << " polynomial: ";
        for (int i = 0; i <= poly.degree; i++) {
            in >> poly.coefficients[i];
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly) {
        for (int i = poly.degree; i >= 0; i--) {
            if (poly.coefficients[i] != 0) {
                out << poly.coefficients[i] << "x^" << i;
                if (i > 0) out << " + ";
            }
        }
        return out;
    }
};

int main() {
    Polynomial p1(2), p2(2);
    std::cin >> p1 >> p2;
    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Product: " << prod << std::endl;

    return 0;
}
