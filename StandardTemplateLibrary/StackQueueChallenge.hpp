// STL Challenge 4 - Stack and Queue - Identifying Palindrome Strings
#ifndef StackQueueChallenge_hpp
#define StackQueueChallenge_hpp

#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string &s) {
    std::stack<char> stack;
    std::queue<char> queue;
    for (char c: s) {
        // ignoring spaces and punctuations
        if (!std::isspace(c) && !std::ispunct(c)) {
            c = std::tolower(c);
            stack.push(c);
            queue.push(c);
        }
    }
    
    while (!stack.empty()) {
        if (stack.top() != queue.front()) {
            return false;
        } else {
            stack.pop();
            queue.pop();
        }
    }
    
    return true;
}

void stack_queue_challenge() {
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
    
    std::cout << std::boolalpha;
    std::cout
        << std::setw(8) << std::left << "Result" << "String"
    << std::endl;
    
    for (const auto &s: test_strings) {
        std::cout
            << is_palindrome(s) << "\t[ " << s << " ]"
        << std::endl;
    }
    
    std::cout << std::endl;
}

#endif /* StackQueueChallenge_hpp */
