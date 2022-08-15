#ifndef Trust_Account_hpp
#define Trust_Account_hpp
#include "Savings_Account.hpp"

/*

 Trust Account:
 -> Has a name, a balance, and an interest rate
 -> The Trust account deposit works just like a savings account deposit.
    * However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to
      the account.

 -> The Trust account withdrawal should only allow 3 withdrawals per year and each of these
    must be less than 20% of the account balance.
    * You don't have to keep track of calendar time for this application, just make sure
      the 4th withdrawal fails :)

 */

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
protected:
    int withdrawals;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    // Deposits of $5000.00 or more will recieve $50 bonus
    bool deposit(double amount);

    // Only allowed max of 3 withdrawals, each can be up to max of 20% of balance
    bool withdraw(double amount);
};

#endif /* Trust_Account_hpp */

