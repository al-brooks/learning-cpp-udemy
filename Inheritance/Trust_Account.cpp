#include "Trust_Account.hpp"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
: Savings_Account{name, balance, int_rate}, withdrawals{0} {}

/*
    The Trust account deposit works just like a savings account deposit.
    * However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to
      the account.
*/

bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_Account::deposit(amount);
}

/*
    The Trust account withdrawal should only allow 3 withdrawals per year and each of these
    must be less than 20% of the account balance.
    * You don't have to keep track of calendar time for this application, just make sure
      the 4th withdrawal fails :)
*/

bool Trust_Account::withdraw(double amount) {
    if (withdrawals >= max_withdrawals || amount > (balance * max_withdraw_percent)) {
        return false;
    } else {
        ++withdrawals;
        return Savings_Account::withdraw(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": "
    << account.balance << ", " << account.int_rate << "%, "
    << "withdrawals: " << account.withdrawals << "]";

    return os;
}

