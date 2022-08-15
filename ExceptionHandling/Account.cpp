#include "Account.hpp"

Account::Account(std::string name, double balance)
: name{name}, balance{balance} {
    if (balance < 0.0)
        throw IllegalBalanceException{};
}

bool Account::deposit(double amount) {
    if (amount < 0) {
        return false;
    } else {
        balance += amount;
        std::cout << "Deposit is Successful for Account: " << name << std::endl;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        std::cout << "Withdraw is Successful for Account: " << name << std::endl;
        return true;
    } else {
        throw InsufficientFundsException{};
    }
}


double Account::get_balance() const { return balance; }

void Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "\nAccount: " << name << "\nBalance: $" << balance
    << "\n";
}


