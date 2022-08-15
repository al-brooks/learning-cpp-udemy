#include "Savings.hpp"

Savings::Savings(std::string name, double balance, double int_rate)
: Account{name, balance}, int_rate{int_rate} {}

bool Savings::deposit(double amount) {
    amount += amount * (int_rate / 100);
    return Account::deposit(amount);
}

bool Savings::withdraw(double amount) {
    return Account::withdraw(amount);
}

void Savings::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "\nSavings Account: " << name << "\nBalance: $" << balance
    << "\nInterest Rate: " << int_rate << "%\n";
}
