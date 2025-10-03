// Write a C++ program to demonstrate pointer arithmetic by creating an array 
// of integers and using pointers to traverse and manipulate the array elements. 
// Implement functions to calculate the sum, average, and maximum value of 
// the array using pointer arithmetic.

#include<iostream>
using namespace std;

int main(){
    int n, sum = 0, maxVal;
    double average;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    cin >> arr[0];
    sum = maxVal = arr[0];
    for (int i = 1; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];}
    average = static_cast<double>(sum) / n;
    cout << "Sum: " << sum << "\nAverage: " << average << "\nMax: " << maxVal << endl;
    return 0;
}
