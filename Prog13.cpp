// Create a class InventoryItem with attributes itemID, itemName, and 
// quantity, implementing default, parameterized, and copy constructors, 
// methods to add, remove, and display inventory items, overloading the ++ 
// and -- operators to increase and decrease item quantity, and implementing 
// dynamic memory allocation for inventory items.
 
#include <iostream>
#include <string>
using namespace std;

class InventoryItem {
private:
    int itemID;
    string itemName;
    int* quantity;

public:
    InventoryItem() : itemID(0), itemName("Unknown") {
        quantity = new int(0);
    }
    InventoryItem(int id, const string& name, int qty) : itemID(id), itemName(name) {
        quantity = new int(qty);
    }
    InventoryItem(const InventoryItem& other) : itemID(other.itemID), itemName(other.itemName) {
        quantity = new int(*other.quantity);
    }
    ~InventoryItem() {
        delete quantity;
    }
    void addItem(int qty) {
        *quantity += qty;
        cout << qty << " items added. New quantity: " << *quantity << endl;
    }
    void removeItem(int qty) {
        if (*quantity >= qty) {
            *quantity -= qty;
            cout << qty << " items removed. New quantity: " << *quantity << endl;
        } else {
            cout << "Error: Insufficient quantity to remove." << endl;
        }
    }
    void displayItem() const {
        cout << "Item ID: " << itemID << ", Name: " << itemName << ", Quantity: " << *quantity << endl;
    }
    InventoryItem& operator++() {
        ++(*quantity);
        return *this;
    }
    InventoryItem& operator--() {
        if (*quantity > 0) {
            --(*quantity);
        } else {
            cout << "Error: Quantity cannot be negative." << endl;
        }
        return *this;
    }
    InventoryItem operator++(int) {
        InventoryItem temp(*this);
        ++(*quantity);
        return temp;
    }
    InventoryItem operator--(int) {
        InventoryItem temp(*this);
        if (*quantity > 0) {
            --(*quantity);
        } else {
            cout << "Error: Quantity cannot be negative." << endl;
        }
        return temp;
    }
};
int main() {
    InventoryItem item1(101, "Laptop", 5);
    item1.displayItem();
    item1.addItem(3);
    item1.removeItem(2);
    ++item1;
    item1.displayItem();
    item1--;
    item1.displayItem();
    InventoryItem item2 = item1;
    item2.displayItem();
    item2.addItem(10);
    item2.displayItem();
    item1.displayItem();
    return 0;
}