//Create a base class Animal with a virtual function makeSound(). Derive 
//classes Dog and Cat from Animal, each implementing makeSound(). Write a 
//function playWithAnimal() that takes a pointer to Animal and calls 
//makeSound(). Demonstrate polymorphism by calling playWithAnimal() with 
//pointers to Dog and Cat.

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "The animal makes a sound." << endl;
    }
    virtual ~Animal() {}
};
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "The dog barks excitedly: Woof! Woof!" << endl;
    }
};
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "The cat meows softly: Meow... Meow..." << endl;
    }
};
void playWithAnimal(Animal* animal) {
    cout << "Let's play with the animal!" << endl;
    animal->makeSound();
    cout << "What a lovely sound!" << endl;
}
int main() {
    Dog dog;
    Cat cat;
    
    cout << "Playing with the dog:" << endl;
    playWithAnimal(&dog);

    cout << "\nPlaying with the cat:" << endl;
    playWithAnimal(&cat);

    return 0;
}
