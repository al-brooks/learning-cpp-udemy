#include <cctype>
#include <iostream>
#include <vector>
#include <iomanip>

#include "DequeChallenge.hpp"

void deque_challenge();


int main() {
    deque_challenge();
    std::cout << std::endl;
    return 0;
}

void deque_challenge() {
    DequeChallenge solution;
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout
            << std::setw(8) << std::left << solution.is_palindrome(s)
            << ": " << s
        << std::endl;
    }
}
