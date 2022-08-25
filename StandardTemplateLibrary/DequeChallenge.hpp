#ifndef DequeChallenge_hpp
#define DequeChallenge_hpp
#include <deque>
#include <string>
#include <algorithm>

class DequeChallenge {
public:
    bool is_palindrome(const std::string &s) {
        std::deque<char> deque;
        for (int i = 0; i < s.size(); ++i) {
            if (std::isalpha(s[i])) {
                deque.push_front(std::tolower(s[i]));
            }
        }
        
        // since deque's allow front and back access
        // take advantage by using two pointer tech
        
        char front{};
        char back{};
        
        while (deque.size() > 1) {
            front = deque.front();
            back = deque.back();
            deque.pop_front();
            deque.pop_back();
            if (front != back)
                return false;
        }
        
        return true;
    }
};

// test solution:
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

#endif /* DequeChallenge_hpp */
