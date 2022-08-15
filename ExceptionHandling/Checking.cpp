#include "Checking.hpp"

Checking::Checking(std::string name, double balance)
: Account{name, balance} {}

bool Checking::deposit(double amount) {
    return Account::deposit(amount);
}

bool Checking::withdraw(double amount) {
    amount += withdraw_fee;
    return Account::withdraw(amount);
}

void Checking::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "\nChecking Account: " << name << "\nBalance: $" << balance
    << "\n";
}

