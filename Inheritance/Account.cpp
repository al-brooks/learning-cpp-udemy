#include "Account.hpp"

Account::Account(std::string name, double balance)
: name{name}, balance{balance} {}

// Operator Overloading

Account Account::operator+=(const double rhs) {
    this->balance += rhs;
    return *this;
}

Account Account::operator-=(const double rhs) {
    this->balance -= rhs;
    return *this;
}

bool Account::deposit(double amount) {
    if (amount < 0) {
        return false;
    } else {
        *this += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        *this -= amount;
        return true;
    } else {
        return false;
    }
}

double Account::get_balance() const { return balance; }

std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "[Account: " << account.name << ": "
    << account.balance << "]";
    
    return os;
}

