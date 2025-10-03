// Create a base class Vehicle with attributes make and model, and methods 
// start() and stop(). Derive classes Car, Truck, and Motorcycle from Vehicle. 
// Use dynamic memory allocation (new and delete operators) to create and 
// manage objects of these classes. Implement a function to display details of 
// all vehicles. 

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
public:
    Vehicle(string m, string mod) : make(m), model(mod) {}
    virtual void start() {
        cout << make << " " << model << " is starting." << endl;
    }
    virtual void stop() {
        cout << make << " " << model << " is stopping." << endl;
    }
    virtual void displayDetails() {
        cout << "Make: " << make << ", Model: " << model << endl;
    }
    virtual ~Vehicle() {
        cout << "Vehicle " << make << " " << model << " is being destroyed." << endl;
    }
};
class Car : public Vehicle {
public:
    Car(string m, string mod) : Vehicle(m, mod) {}
    void displayDetails() override {
        cout << "Car - ";
        Vehicle::displayDetails();
    }
    void start() override {
        cout << make << " " << model << " car is starting." << endl;
    }
    void stop() override {
        cout << make << " " << model << " car is stopping." << endl;
    }
    ~Car() {
        cout << "Car " << make << " " << model << " is being destroyed." << endl;
    }
};
class Truck : public Vehicle {
public:
    Truck(string m, string mod) : Vehicle(m, mod) {}
    void displayDetails() override {
        cout << "Truck - ";
        Vehicle::displayDetails();
    }
    void start() override {
        cout << make << " " << model << " truck is starting." << endl;
    }
    void stop() override {
        cout << make << " " << model << " truck is stopping." << endl;
    }

    ~Truck() {
        cout << "Truck " << make << " " << model << " is being destroyed." << endl;
    }
};
class Motorcycle : public Vehicle {
public:
    Motorcycle(string m, string mod) : Vehicle(m, mod) {}

    void displayDetails() override {
        cout << "Motorcycle - ";
        Vehicle::displayDetails();
    }

    void start() override {
        cout << make << " " << model << " motorcycle is starting." << endl;
    }
    void stop() override {
        cout << make << " " << model << " motorcycle is stopping." << endl;
    }

    ~Motorcycle() {
        cout << "Motorcycle " << make << " " << model << " is being destroyed." << endl;
    }
};
void displayAllVehicles(Vehicle* vehicles[], int count) {
    for (int i = 0; i < count; i++) {
        vehicles[i]->displayDetails();
        vehicles[i]->start();
        vehicles[i]->stop();
        cout << endl;
    }
}
int main(){
    Vehicle* car = new Car("Toyota", "Corolla");
    Vehicle* truck = new Truck("Ford", "F-150");
    Vehicle* motorcycle = new Motorcycle("Harley-Davidson", "Sportster");

    Vehicle* vehicles[] = {car, truck, motorcycle};
    displayAllVehicles(vehicles, 3);
    delete car;
    delete truck;
    delete motorcycle;

    return 0;
}
