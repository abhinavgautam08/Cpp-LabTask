//Create a class Student with attributes studentID, name, and grades (an array 
//of integers), implementing default, parameterized constructors, and a 
//destructor, methods to calculate the average grade and display student 
//details, using constant member functions to display details, and 
//implementing dynamic memory allocation for the grades array.

#include<iostream>
using namespace std;

class Student{
public:
    int studentID;
    string name;
    int *grades;
    int numGrades;

    Student() {
        studentID = 0;
        name = "";
        numGrades = 0;
        grades = nullptr;
    }
    Student(int id, string n, int num) {
        studentID = id;
        name = n;
        numGrades = num;
        grades = new int[numGrades];
    }
    ~Student() {
        delete[] grades;
    }
};

int main() {
    int id, num;
    string name;
    cout << "Student ID: ";
    cin >> id;
    cin.ignore();
    cout << "Name: ";
    getline(cin, name);
    cout << "No. of grades: ";
    cin >> num;
    Student student(id, name, num);
    if (num > 0) {
        student.grades = new int[num];
        cout << "Enter grades: ";
        for (int i = 0; i < num; ++i) {
            cin >> student.grades[i];
        }
    }
    cout << "\nStudent Details:\n";
    cout << "Student ID: " << student.studentID << endl;
    cout << "Name: " << student.name << endl;
    cout << "Grades: ";
    if (num > 0) {
        for (int i = 0; i < num; ++i) {
            cout << student.grades[i] << " ";
        }
    } else {
        cout << "No grades entered.";
    }
    cout << endl;
    delete[] student.grades;
    return 0;
}