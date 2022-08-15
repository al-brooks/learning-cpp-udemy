#ifndef Savings_Account_hpp
#define Savings_Account_hpp
#include "Account.hpp"

/*

 Savings Account is a type of Account
 -> Adds and Interest Rate
 -> Withdraw: Same as Account
 -> Deposit:
    * Amount given to deposit will be incremented by ((amount * int_rate) / 100)
    * The updated amount will be deposited

 */

class Savings_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    // Inherited the Account::withdraw method
};

#endif /* Savings_Account_hpp */

