// Two Approaches (with modulo, without)

#include <iostream>
#include <cmath>

int main()
{
    int cents{};
    std::cout << "Enter the number of U.S. Cents that you want to convert: ";
    std::cin >> cents;

    
    int dollars{}, quarters{}, dimes{}, nickels{}, pennys{};
    int cents_one = cents;
    int cents_two = cents;
    
// method one:

    dollars = std::floor(cents_one/100);
    cents_one -= dollars * 100;

    quarters = std::floor(cents_one/25);
    cents_one -= quarters * 25;

    dimes = std::floor(cents_one/10);
    cents_one -= dimes * 10;

    nickels = std::floor(cents_one/5);
    cents_one -= nickels * 5;

    pennys = std::floor(cents_one/1);
    
    std::cout << "\n===== Method One =====" << std::endl;
    std::cout << "dollars: " << dollars << std::endl;
    std::cout << "quarters: " << quarters << std::endl;
    std::cout << "dimes: " << dimes << std::endl;
    std::cout << "nickels: " << nickels << std::endl;
    std::cout << "pennys: " << pennys << std::endl;

// method two: using modulo
    
    int balance{};
    
    dollars = cents_two / 100;
    balance = cents % 100;
    
    quarters = balance / 25;
    balance %= 25;

    dimes = balance / 10;
    balance %= 10;

    nickels = balance / 5;
    balance %= 5;

    pennys = balance;

    std::cout << "\n===== Method Two =====" << std::endl;
    std::cout << "dollars: " << dollars << std::endl;
    std::cout << "quarters: " << quarters << std::endl;
    std::cout << "dimes: " << dimes << std::endl;
    std::cout << "nickels: " << nickels << std::endl;
    std::cout << "pennys: " << pennys << std::endl;

    std::cout << std::endl;
    return 0;
    
}
