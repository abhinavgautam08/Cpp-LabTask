// Write a C++ program that compresses a string using the counts of repeated 
// characters. For example, the string "aabcccccaaa" would become 
// "a2b1c5a3". If the "compressed" string would not become smaller than the 
// original string, the function should return the original string. Use streams for 
// efficient string manipulation. 

#include <iostream>
#include <sstream>
#include <string>

std::string compressString(const std::string& input) {
    if (input.empty()) return input;

    std::ostringstream compressedStream;
    int count = 1;

    for (size_t i = 1; i < input.length(); ++i) {
        if (input[i] == input[i - 1]) {
            ++count;
        } else {
            compressedStream << input[i - 1] << count;
            count = 1;
        }
    }
    compressedStream << input[input.length() - 1] << count;
    std::string compressedString = compressedStream.str();
    return (compressedString.length() < input.length()) ? compressedString : input;
}
int main() {
    std::string input;
    std::cout << "Please enter a string to compress: ";
    std::getline(std::cin, input);
    std::string result = compressString(input);
    std::cout << "Here is the compressed version of your string: " << result << std::endl;

    return 0;
}
