// Write a template-based function in C++ to sort an array of any data type 
// using the quicksort algorithm. Ensure the function works with different data 
// types such as integers, floating-point numbers, and strings. 


#include <iostream>
#include <string>
#include <vector>

template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quicksort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> intArray = {34, 7, 23, 32, 5, 62};
    std::cout << "Original integer array: ";
    printArray(intArray);
    quicksort(intArray, 0, intArray.size() - 1);
    std::cout << "Sorted integer array: ";
    printArray(intArray);

    std::vector<float> floatArray = {3.14, 2.71, 1.61, 4.67, 0.577};
    std::cout << "\nOriginal float array: ";
    printArray(floatArray);
    quicksort(floatArray, 0, floatArray.size() - 1);
    std::cout << "Sorted float array: ";
    printArray(floatArray);

    std::vector<std::string> strArray = {"apple", "orange", "banana", "grape", "kiwi"};
    std::cout << "\nOriginal string array: ";
    printArray(strArray);
    quicksort(strArray, 0, strArray.size() - 1);
    std::cout << "Sorted string array: ";
    printArray(strArray);

    return 0;
}
