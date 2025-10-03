// Write a C++ program to perform basic matrix operations such as addition, 
// subtraction, and multiplication. Use two-dimensional arrays to represent the 
// matrices and implement functions for each operation. Ensure the program 
// handles matrices of appropriate sizes and displays the results accurately. 

#include <iostream>
using namespace std;

const int max_size = 10;

int main() {
    int rows, cols;
    cout << "Enter number of rows & columns: ";
    cin >> rows >> cols;
    int A[max_size][max_size], 
	    B[max_size][max_size], 
		result[max_size][max_size];
    cout << "Enter elements of 1st matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];}}
    cout << "Enter elements of 2nd matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            cin >> B[i][j];}}
    cout << "Sum of matrices:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
            cout << result[i][j] << " ";}
        cout << endl;}
    cout << "Difference of matrices:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
            cout << result[i][j] << " ";}
        cout << endl;}
    int colsB;
    cout << "Enter number of columns for second matrix in multiplication: ";
    cin >> colsB;
    int B_mult[max_size][max_size], product[max_size][max_size];
    cout << "Enter elements of second matrix for multiplication:" << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B_mult[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colsB; j++) {
            product[i][j] = 0;}
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < cols; k++) {
                product[i][j] += A[i][k] * B_mult[k][j];}
        }
    }
    cout << "Product of matrices:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << product[i][j] << " ";}
        cout << endl;}
    return 0;
}
