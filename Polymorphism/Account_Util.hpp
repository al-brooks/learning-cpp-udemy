#ifndef Account_Util_hpp
#define Account_Util_hpp
#include <vector>
#include "Account.hpp"

// Global Functions
// Utility Helpers for Account Objects

// We're pointing to Account* in order to use Dynamic Polymorphism
void display(const std::vector<Account*> &accounts);
void deposit(std::vector<Account*> &accounts, double amount);
void withdraw(std::vector<Account*> &accounts, double amount);

#endif /* Account_Util_hpp */

