// Write a C++ program to find all unique palindromic substrings in a given 
// string. The function should take a string as input and return a set of strings 
// containing all unique palindromic substrings. 

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    unordered_set<string> palindromes;
    int n = input.length();
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            string sub = input.substr(i, j - i + 1);
            string rev = string(sub.rbegin(), sub.rend());
            if (sub == rev){
                palindromes.insert(sub);
            }
        }
    }
    cout << "Unique palindromic substrings:\n";
    for (const string &palindrome : palindromes){
        cout << palindrome << "\n";}
    
    return 0;
}
