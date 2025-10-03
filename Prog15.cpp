// Develop a Vehicle Management System that demonstrates different types of 
// inheritance and polymorphism in C++. The system should manage various 
// types of vehicles, including cars, trucks, and motorcycles, and should be able 
// to perform operations such as adding new vehicles, displaying vehicle details, 
// and comparing vehicles. 

#include <iostream>
#include <vector>
using namespace std;
class Vehicle{
protected:
    string brand;
    int year;
public:Vehicle(string b, int y) : brand(b), year(y) {}
    virtual void displayInfo() = 0;
    virtual ~Vehicle(){}
};
class Car : public Vehicle {
private:int seats;
public:Car(string b, int y, int s) : Vehicle(b, y), seats(s) {}
    void displayInfo() override {
        cout << "Car | Brand: " << brand << " | Year: " << year << " | Seats: " << seats << endl;}
};
class Truck : public Vehicle {
private:double loadCapacity;
public:Truck(string b, int y, double c) : Vehicle(b, y), loadCapacity(c) {}
    void displayInfo() override {
        cout << "Truck | Brand: " << brand << " | Year: " << year << " | Load Capacity: " << loadCapacity << " tons" << endl;}
};

class Motorcycle : public Vehicle{
private:bool hasSidecar;
public:Motorcycle(string b, int y, bool s) : Vehicle(b, y), hasSidecar(s) {}
    void displayInfo() override {
        cout <<"Bike | Brand: " << brand << " | Year: " << year << " | Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;}
};

int main(){
    vector<Vehicle*> vehicles;
    vehicles.push_back(new Car("Toyota", 2020, 5));
    vehicles.push_back(new Truck("Ford", 2018, 3.5));
    vehicles.push_back(new Bike("Harley-Davidson", 2019, false));
    cout << "\nVehicle Details:\n";
    cout << "-----------------------\n";
    for (Vehicle* v : vehicles) {
        v->displayInfo();}
    for (Vehicle* v : vehicles){
        delete v;}
    return 0;
}