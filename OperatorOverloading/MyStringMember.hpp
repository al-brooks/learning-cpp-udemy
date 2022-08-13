#ifndef MyStringMember_hpp
#define MyStringMember_hpp
#include <iostream> // io library
#include <cstring> // strcpy, strlen, etc.
#include <cctype> // tolower, toupper, etc.

class MyStringMember {
    friend std::ostream &operator<<(std::ostream &os, const MyStringMember &rhs);
    friend std::istream &operator>>(std::istream &is, MyStringMember &rhs);
private:
    char *str; // pointer to char[] that holds C-Style String
public:
    MyStringMember();
    MyStringMember(const char *s);
    MyStringMember(const MyStringMember &source); // Copy Constructor
    MyStringMember(MyStringMember &&source); // Move Constructor
    ~MyStringMember();
    
    // Assignments
    MyStringMember &operator=(const MyStringMember &rhs); // Copy Assignment
    MyStringMember &operator=(MyStringMember &&rhs); // Move Assignment
    
    // Other Operators
    MyStringMember operator-() const; // lowercase
    bool operator==(const MyStringMember &rhs) const; // compare equal
    bool operator!=(const MyStringMember &rhs) const; // compare not
    bool operator<(const MyStringMember &rhs) const; // compare less
    bool operator>(const MyStringMember &rhs) const; // compare greater
    MyStringMember operator+(const MyStringMember &rhs) const; // concat to new obj
    MyStringMember operator+=(const MyStringMember &rhs); // concat to lhs
    MyStringMember operator*(int n) const; // repeat to new obj
    MyStringMember operator*=(int n); // repeat to lhs
    
    // Other Functions
    void display() const;
    
    // Getters
    int get_length() const;
    const char* get_str() const;
};

#endif /* MyStringMember_hpp */
