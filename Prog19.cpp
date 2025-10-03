// Create a base class Person with attributes name and age. Derive classes 
// Student and Teacher from Person. Further derive a class TeachingAssistant 
// from both Student and Teacher. Use a virtual base class to avoid ambiguity 
// in accessing attributes of Person. 

#include <iostream>
#include <string>

class Person {
public:std::string name;
    int age;
    Person(const std::string& name, int age) : name(name), age(age) {}
    virtual ~Person() {}
    virtual void introduce() const {
        std::cout << "Hello, my name is " << name << " and I am " << age << " years old." << std::endl;}
};
class Student : virtual public Person {
public:Student(const std::string& name, int age) : Person(name, age){}
    void introduce() const override{
        std::cout << "Hi, I'm " << name << ", a student, and I am " << age << " years old." << std::endl;}
};
class Teacher : virtual public Person {
public:Teacher(const std::string& name, int age) : Person(name, age) {}
    void introduce() const override {
        std::cout << "Hello, I am " << name << ", a teacher, and I am " << age << " years old." << std::endl;}
};
class TeachingAssistant : public Student, public Teacher {
public:TeachingAssistant(const std::string& name, int age)
     : Person(name, age), Student(name, age), Teacher(name, age){}
    void introduce() const override {
        std::cout << "Hi, I am " << name << ", a teaching assistant, and I am " << age << " years old." << std::endl;}
};
int main(){TeachingAssistant ta("Abhinav Adarsh", 21);
     ta.introduce();
     return 0;
}