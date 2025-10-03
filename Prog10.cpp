// Create a class Matrix that represents a 2D matrix with dynamic memory 
// allocation, implementing default, parameterized constructors, and a 
// destructor, methods to add, subtract, and multiply matrices, overloading the 
// [] operator to access matrix elements, and inline functions for basic matrix 
// operations.

#include<iostream>
using namespace std;

class Matrix{
public:
    int rows, cols;
    int **data;
    Matrix(){
        rows = 0;
        cols = 0;
        data = nullptr;
    }
    Matrix(int r, int c){
        rows = r;
        cols = c;
        data = new int *[rows];
        for (int i = 0; i < rows; ++i){
            data[i] = new int[cols];}
    }
    ~Matrix(){
        for (int i = 0; i < rows; ++i){
            delete[] data[i];}
        delete[] data;}
}; 
int main(){
    int r, c;
    cout << "Enter no. of rows and columns: ";
    cin >> r >> c;
    Matrix mat1(r, c), mat2(r, c);
    cout << "Enter elem for 1st matrix:" << endl;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cin >> mat1.data[i][j];}
    }
    cout << "Enter elem for 2nd matrix:" << endl;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cin >> mat2.data[i][j];}
    }
    cout << "1st Matrix:" << endl;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cout << mat1.data[i][j] << " ";}
        cout << endl;
    }
    cout << "2nd Matrix:" << endl;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cout << mat2.data[i][j] << " ";}
        cout << endl;
    }
    return 0;
}
