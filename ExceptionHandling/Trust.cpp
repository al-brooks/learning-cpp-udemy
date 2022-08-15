#include "Trust.hpp"

Trust::Trust(std::string name, double balance, double int_rate)
: Savings{name, balance, int_rate}, withdrawals(0) {}

bool Trust::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings::deposit(amount);
}

bool Trust::withdraw(double amount) {
    if (withdrawals >= max_withdrawals || amount > (balance * max_withdraw_percent)) {
        std::cout << "Withdrawal Amount is greater than Accepted Limit" << std::endl;
        return false;
    } else {
        ++withdrawals;
        return Savings::withdraw(amount);
    }
}

void Trust::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "\nTrust Account: " << name << "\nBalance: $" << balance
    << "\nInterest Rate: " << int_rate << "%"
    << "\nNumber of Withdrawals: " << withdrawals << "\n";
}
