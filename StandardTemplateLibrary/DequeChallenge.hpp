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

#endif /* DequeChallenge_hpp */
