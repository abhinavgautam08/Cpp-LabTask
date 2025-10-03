//Write a C++ program that reads a text file, processes the text to remove 
//punctuation, convert to lowercase, and count the frequency of each word. 
//Use string streams for text manipulation and file streams for reading and 
//writing files.

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cctype>
#include <algorithm>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }
    if (!outputFile) {
        std::cerr << "Error: Unable to open output file." << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string line, word;
    
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        while (ss >> word) {
            word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (!word.empty()) {
                wordCount[word]++;
            }
        }
    }
    
    for (const auto& pair : wordCount) {
        outputFile << pair.first << " : " << pair.second << std::endl;
    }

    std::cout << "Processing complete. Check output.txt for results." << std::endl;

    return 0;
}
