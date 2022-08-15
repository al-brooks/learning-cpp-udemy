#include <iostream>
#include <memory>
#include "Account.hpp"
#include "Checking.hpp"
#include "Savings.hpp"
#include "Trust.hpp"
#include "Account_Util.hpp"
#include "IllegalBalanceException.hpp"
#include "InsufficientFundsException.hpp"

using namespace std;

int main() {
    try {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking>("Moe", 510.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(600);
        std::cout << *moes_account << std::endl;
    } catch (const IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    } catch (const InsufficientFundsException &ex) {
        std::cerr << ex.what() << std::endl;
    }

    std::cout << "Program Completed Successfully" << std::endl;
    return 0;
}
