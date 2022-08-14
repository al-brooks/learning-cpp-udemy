#ifndef MyStringFriend_hpp
#define MyStringFriend_hpp
#include <iostream> // io library for insertiona and extraction
#include <cstring> // strcpy, strlen, etc.
#include <cctype> // tolower, toupper, etc.

class MyStringFriend {
    // lowercase
    friend MyStringFriend operator-(const MyStringFriend &obj);
    // equality
    friend bool operator==(const MyStringFriend &lhs, const MyStringFriend &rhs);
    // not equal
    friend bool operator!=(const MyStringFriend &lhs, const MyStringFriend &rhs);
    // less than
    friend bool operator<(const MyStringFriend &lhs, const MyStringFriend &rhs);
    // greater than
    friend bool operator>(const MyStringFriend &lhs, const MyStringFriend &rhs);
    // concat to new obj
    friend MyStringFriend operator+(const MyStringFriend &lhs, const MyStringFriend &rhs);
    // concat to lhs
    friend MyStringFriend operator+=(MyStringFriend &lhs, const MyStringFriend &rhs);
    // repeat to new obj
    friend MyStringFriend operator*(const MyStringFriend &lhs, int n);
    // repeat and assign to lhs
    friend MyStringFriend operator*=(MyStringFriend &lhs,  int n);
    // extraction
    friend std::ostream& operator<<(std::ostream &os, const MyStringFriend &rhs);
    // insertion
    friend std::istream& operator>>(std::istream &is, MyStringFriend &rhs);
private:
    char *str; // pointer to char[] that holds C-Style String
public:
    MyStringFriend(); // no args constructor
    MyStringFriend(const char *s); // overloaded constructor
    MyStringFriend(const MyStringFriend &source); // copy constructor
    MyStringFriend(MyStringFriend &&source); // move constructor
    ~MyStringFriend(); // destructor

    // Assignment
    MyStringFriend &operator=(const MyStringFriend &rhs); // copy assignment
    MyStringFriend &operator=(MyStringFriend &&rhs); // move assignment

    // Other functions
    void display() const;
    int get_length() const;
    const char* get_str() const;
};

#endif /* MyStringFriend_hpp */

