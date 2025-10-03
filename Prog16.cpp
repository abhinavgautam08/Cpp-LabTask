// Create a base class Account with methods deposit() and withdraw(). Derive 
// classes SavingsAccount and CurrentAccount from Account. Overload the 
// deposit() and withdraw() methods in the derived classes to include additional 
// parameters like interest rate for SavingsAccount and overdraft limit for 
// CurrentAccount. 

#include <iostream>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double initialBalance) {
        balance = initialBalance;
    }
    virtual void deposit(double amount) {
        balance += amount;
        cout << "You deposited: " << amount << endl;
        cout << "Your new balance is: " << balance << endl;
    }
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "You withdrew: " << amount << endl;
            cout << "Your new balance is: " << balance << endl;
        } else {
            cout << "Sorry, you don't have enough funds for this withdrawal." << endl;
        }
    }
    double getBalance() const {
        return balance;
    }
};
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance), interestRate(rate) {}
    void deposit(double amount) override {
        Account::deposit(amount);
        double interest = (balance * interestRate) / 100;
        balance += interest;
        cout << "Interest added: " << interest << endl;
        cout << "Your new balance after interest is: " << balance << endl;
    }
    void withdraw(double amount) override {
        if (balance - amount >= 0) {
            Account::withdraw(amount);
            double interestDeducted = (amount * interestRate) / 100;
            cout << "Interest deducted: " << interestDeducted << endl;
        } else {
            cout << "You don't have enough funds for this withdrawal, including interest." << endl;
        }
    }
};
class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(double initialBalance, double limit)
        : Account(initialBalance), overdraftLimit(limit) {}
    void deposit(double amount) override {
        Account::deposit(amount);
        cout << "Your current account balance with overdraft limit is: " << balance << endl;
    }
    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            Account::withdraw(amount);
            cout << "You can withdraw within your overdraft limit of: " << overdraftLimit << endl;
        } else {
            cout << "Sorry, this withdrawal exceeds your overdraft limit." << endl;
        }
    }
};
int main() {
    SavingsAccount savings(1000, 5.0);
    cout << "\n--- Savings Account ---\n";
    savings.deposit(200);
    savings.withdraw(150);

    cout << "\n----------------------------\n";
    CurrentAccount current(1000, 500);
    cout << "\n--- Current Account ---\n";
    current.deposit(300);
    current.withdraw(1300);
    current.withdraw(2500);

    return 0;
}
