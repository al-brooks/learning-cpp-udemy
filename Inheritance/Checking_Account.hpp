#ifndef Checking_Account_hpp
#define Checking_Account_hpp
#include "Account.hpp"

/*

 Checking Account:
 -> Has a name and balance
 -> Has a fee of $1.50 per withdrawal

 */

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double withdraw_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    // inherits deposit
    bool withdraw(double amount);
};


#endif /* Checking_Account_hpp */

