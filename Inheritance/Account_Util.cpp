#include <iostream>
#include "Account_Util.hpp"

// Helper Functions for Account Class
// ==================================

// Display Account objects in a vector of Account objects
void display(const std::vector<Account> &accounts) {
    std::cout << "\n===== Accounts =====" << std::endl;
    for (const Account &acc: accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account> &accounts, double amount) {
    std::cout << "\n===== Despositing to Accounts =====" << std::endl;
    for (Account &acc: accounts) {
        if (acc.deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        } else {
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
        }
    }

}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account> &accounts, double amount) {
    std::cout << "\n===== Withdrawing from Accounts =====" << std::endl;
    for (Account &acc: accounts) {
        if (acc.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        } else {
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
        }
    }
}


// Helper Functions for Savings_Account Class
// =========================================

// Display Savings_Account objects in a vector of objects
void display(const std::vector<Savings_Account> &accounts) {
    std::cout << "\n===== Savings Accounts =====" << std::endl;
    for (const Savings_Account &acc: accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposit(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << "\n===== Depositing to Savings Accounts =====" << std::endl;
    for (Savings_Account &acc: accounts) {
        if (acc.deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        } else {
            std::cout << "Failed to Deposit " << amount << " to " << acc << std::endl;
        }
    }

}

// Withdraw supplied amount from each Savings Account object in vector
void withdraw(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << "\n===== Withdrawing from Savings Accounts =====" << std::endl;
    for (Savings_Account &acc: accounts) {
        if(acc.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        } else {
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
        }
    }
}

// Utility helper functions for Checking_Account Class

void display(const std::vector<Checking_Account> &accounts) {
    std::cout << "\n===== Checking Accounts =====" << std::endl;
    for (const Checking_Account &acc: accounts)
        std::cout << acc << std::endl;
}

void deposit(std::vector<Checking_Account> &accounts, double amount) {
    std::cout << "\n===== Despositing to Checking Accounts =====" << std::endl;
    for (Checking_Account &acc: accounts) {
        if (acc.deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        } else {
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
        }
    }
}

void withdraw(std::vector<Checking_Account> &accounts, double amount) {
    std::cout << "\n===== Withdrawing from Checking Accounts =====" << std::endl;
    for (Checking_Account &acc: accounts) {
        if(acc.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        } else {
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
        }
    }
}

// Utility helper functions for Trust_Account Class

void display(const std::vector<Trust_Account> &accounts) {
    std::cout << "\n===== Trust Accounts =====" << std::endl;
    for (const Trust_Account &acc: accounts)
        std::cout << acc << std::endl;
}

void deposit(std::vector<Trust_Account> &accounts, double amount) {
    std::cout << "\n===== Despositing to Trust Accounts =====" << std::endl;
    for (Trust_Account &acc: accounts) {
        if (acc.deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        } else {
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
        }
    }
}

void withdraw(std::vector<Trust_Account> &accounts, double amount) {
    std::cout << "\n===== Withdrawing from Trust Accounts =====" << std::endl;
    for (Trust_Account &acc: accounts) {
        if(acc.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        } else {
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
        }
    }
}

