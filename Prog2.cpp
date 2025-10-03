// Create a C++ program that checks if a given number is a prime number. The 
// program should prompt the user to enter a number, then use control 
// structures and functions to determine if the number is prime. Display an 
// appropriate message indicating the result.

#include <iostream>
using namespace std;

bool isPrime(int num){
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++){
     if (num % i == 0) return false;}
      return true;}
int main() {
    int num;
     cout << "Enter a No.: ";
      cin >> num;
    if (isPrime(num)) {
        cout << num << " is a Prime number" << endl;
    }else{
        cout << num << " is not a Prime number" << endl;
    }
    return 0;
}
