#ifndef Checking_hpp
#define Checking_hpp

#include "Account.hpp"

class Checking: public Account {
private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double withdraw_fee = 1.5;
public:
    Checking(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
    virtual ~Checking() = default;
};

#endif /* Checking_hpp */
