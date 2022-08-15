#ifndef Account_hpp
#define Account_hpp
#include <iostream>
#include <string>

class Account {
    // Overloaded Insertion Operator: Allows you to put Accounts on stream easily
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
    // constexpr - pg. 65 C++ Primer
    // static object = pg. 205 C++ Primer
    // Below are constants only available to the class or within class scope
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    // Account(std::string name = "Unnamed Account", double balance = 0.0);
    Account(std::string name = def_name, double balance = def_balance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
    // Operator Overloading
    Account operator+=(const double rhs); // add amount
    Account operator-=(const double rhs); // subtract amount
};

#endif /* Account_hpp */

