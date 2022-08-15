#include "Account_Util.hpp"

// Helper Functions for Account Class

// Display
void display(const std::vector<Account*> &accounts) {
    for (auto acc: accounts)
        std::cout << *acc << std::endl;
}

// Deposit
void deposit(std::vector<Account*> &accounts, double amount) {
    for (auto acc: accounts)
        if (acc->deposit(amount)) {
            std::cout << "Deposited: " << amount << " to "
            << *acc << std::endl;
        } else {
            std::cout << "FAILED to Deposit " << amount << " to "
            << *acc << std::endl;
        }
}

// Withdraw
void withdraw(std::vector<Account*> &accounts, double amount) {
    for (auto acc: accounts)
        if (acc->withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from "
            << *acc << std::endl;
        } else {
            std::cout << "FAILED to Withdraw " << amount << " from "
            << *acc << std::endl;
        }
}


