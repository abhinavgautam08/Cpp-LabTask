// Create a C++ program that generates the Fibonacci sequence up to a 
// specified number of terms. Use a loop and control structures to generate the 
// sequence and store the terms in an array. Display the generated sequence 
// as the output. 

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    if (n <= 0){
        cout << "Please enter a positive integer." << endl;
        return 1;}
    int arr[n];
    arr[0] = 0;
    if (n > 1) arr[1] = 1;
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << "Fibonacci Sequence: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
