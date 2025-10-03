 //Write a C++ program that reads data from a file and processes it. Implement 
//error handling to catch exceptions if the file does not exist, is empty, or 
//cannot be read. Use exception specifications to define the exceptions that the 
//functions might throw. 

#include<iostream>
#include<fstream>
#include<stdexcept>

int main(){
    std::ifstream inputFile("data.txt");
    if (!inputFile){
        throw std::runtime_error("Error: File does not exist or cannot be opened.");}
    inputFile.seekg(0, std::ios::end);
    if (inputFile.tellg() == 0){
        throw std::runtime_error("Error: File is empty.");}
    inputFile.seekg(0, std::ios::beg);
    std::string line;
    while (std::getline(inputFile, line)){
        std::cout << line << std::endl;}
    inputFile.close();
    return 0;
	}
