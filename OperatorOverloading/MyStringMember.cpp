#include "MyStringMember.hpp"

MyStringMember::MyStringMember() : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

MyStringMember::MyStringMember(const char *s) : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

MyStringMember::MyStringMember(const MyStringMember &source) : str{nullptr} {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    std::cout << "Copy Constructor Used" << std::endl;
}

MyStringMember::MyStringMember(MyStringMember &&source) : str{source.str} {
    source.str = nullptr;
    std::cout << "Move Constructor Used" << std::endl;
}

MyStringMember::~MyStringMember() {
    delete [] str;
}

MyStringMember &MyStringMember::operator=(const MyStringMember &rhs) {
    std::cout << "Using Copy Assignment" << std::endl;
    
    if (this == &rhs)
        return *this;
    
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

MyStringMember &MyStringMember::operator=(MyStringMember &&rhs) {
    std::cout << "Using Move Assignment" << std::endl;
    
    if (this == &rhs)
        return *this;
    
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


MyStringMember MyStringMember::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i{0}; i < std::strlen(buff); ++i)
        buff[i] = std::tolower(buff[i]);
    MyStringMember temp{buff};
    delete [] buff;
    return temp;
}

bool MyStringMember::operator==(const MyStringMember &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

bool MyStringMember::operator!=(const MyStringMember &rhs) const {
    return (std::strcmp(str, rhs.str) != 0);
}

bool MyStringMember::operator<(const MyStringMember &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

bool MyStringMember::operator>(const MyStringMember &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

MyStringMember MyStringMember::operator+(const MyStringMember &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    MyStringMember temp{buff};
    delete [] buff;
    return temp;
}

MyStringMember MyStringMember::operator+=(const MyStringMember &rhs) {
    *this = *this + rhs;
    return *this;
}

MyStringMember MyStringMember::operator*(int n) const {
    MyStringMember temp;
    
    for (int i{0}; i < n; ++i) {
        temp = temp + *this;
    }
    
    return temp;
}

MyStringMember MyStringMember::operator*=(int n) {
    *this = *this * n;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const MyStringMember &rhs) {
    os << rhs.str;
    return os;
}

std::istream &operator>>(std::istream &is, MyStringMember &rhs) {
    char *buff = new char[1000];
    is >> buff;
    rhs = MyStringMember{buff};
    delete [] buff;
    return is;
}


void MyStringMember::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

int MyStringMember::get_length() const { return (int) std::strlen(str); }

const char* MyStringMember::get_str() const { return str; }
