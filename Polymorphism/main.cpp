#include <iostream>
#include <vector>
#include <memory>
#include "Account.hpp"
#include "Account_Util.hpp"
#include "Checking.hpp"
#include "Savings.hpp"
#include "Trust.hpp"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    Checking alex{"Alex", 5000};
    cout << alex << endl;

    Account* trust = new Trust("Helena");
    cout << *trust << endl;
    delete trust;

    Account* p1 = new Checking("Pauly", 10000);
    Account* p2 = new Savings("Vinny", 2032);
    Account* p3 = new Trust("Mike");

    std::vector<Account*> accounts{p1, p2, p3};

    display(accounts);
    deposit(accounts, 50000);

    p3->withdraw(30000);


    delete p1;
    delete p2;
    delete p3;

    return 0;
}

