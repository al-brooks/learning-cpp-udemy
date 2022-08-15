#include <iostream>
#include <vector>
#include "Account.hpp"
#include "Savings_Account.hpp"
#include "Checking_Account.hpp"
#include "Trust_Account.hpp"
#include "Account_Util.hpp"

using
std::vector,
std::cout,
std::endl;

int main() {
    cout.precision(2);
    cout << std::fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{"Superman"});
    sav_accounts.push_back(Savings_Account{"Batman", 2000});
    sav_accounts.push_back(Savings_Account{"Wonderwoman", 5000, 5.0});

    display(sav_accounts);
    deposit(sav_accounts, 2000);
    withdraw(sav_accounts, 3000);

    // Checking Account
    vector<Checking_Account> check_accts;
    check_accts.push_back(Checking_Account{});
    check_accts.push_back(Checking_Account{"Alex"});
    check_accts.push_back(Checking_Account{"Helena", 35000});
    check_accts.push_back(Checking_Account{"Penny", 500});

    display(check_accts);
    deposit(check_accts, 1000);
    withdraw(check_accts, 2000);

    // Trust Account
    vector<Trust_Account> trust_accts;
    trust_accts.push_back(Trust_Account{});
    trust_accts.push_back(Trust_Account{"Alejandro"});
    trust_accts.push_back(Trust_Account{"Elena", 24200});
    trust_accts.push_back(Trust_Account{"Penita", 3000, 5.0});

    display(trust_accts);
    deposit(trust_accts, 7000);
    withdraw(trust_accts, 2000);

    for (int i{0}; i < 5; ++i)
        withdraw(trust_accts, 100);

    return 0;
}

