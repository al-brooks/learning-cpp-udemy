#include "MyStringFriend.hpp"

// no args constructor
MyStringFriend::MyStringFriend(): str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// overloaded constructor
MyStringFriend::MyStringFriend(const char *s): str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// copy constructor
MyStringFriend::MyStringFriend(const MyStringFriend &source): str{nullptr} {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    std::cout << "copy constructor used" << std::endl;
}

// move constructor
MyStringFriend::MyStringFriend(MyStringFriend &&source): str{source.str} {
    source.str = nullptr;
    std::cout << "move constructor used" << std::endl;
}

// destructor
MyStringFriend::~MyStringFriend() {
    delete [] str;
}

// copy assignment
MyStringFriend& MyStringFriend::operator=(const MyStringFriend &rhs) {
    std::cout << "using copy assignemnt" << std::endl;

    if (this == &rhs)
        return *this;

    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// move assignment
MyStringFriend& MyStringFriend::operator=(MyStringFriend &&rhs) {
    std::cout << "using move assignment" << std::endl;

    if (this == &rhs)
        return *this;

    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// make lowercase
MyStringFriend operator-(const MyStringFriend &obj) {
    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (size_t i{0}; i < strlen(buff); ++ i) {
        buff[i] = tolower(buff[i]);
    }
    MyStringFriend temp{buff};
    delete [] buff;
    return temp;
}

// equality
bool operator==(const MyStringFriend &lhs, const MyStringFriend &rhs) {
    return (strcmp(lhs.str, rhs.str) == 0);
}

// not equal
bool operator!=(const MyStringFriend &lhs, const MyStringFriend &rhs) {
    return (strcmp(lhs.str, rhs.str) != 0);
}

// less than
bool operator<(const MyStringFriend &lhs, const MyStringFriend &rhs) {
    return (strcmp(lhs.str, rhs.str) < 0);
}

// greater than
bool operator>(const MyStringFriend &lhs, const MyStringFriend &rhs) {
    return (strcmp(lhs.str, rhs.str) > 0);
}

// concat to new object
MyStringFriend operator+(const MyStringFriend &lhs, const MyStringFriend &rhs) {
    char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    MyStringFriend temp{buff};
    delete [] buff;
    return temp;
}

// concat and assign to lhs
MyStringFriend operator+=(MyStringFriend &lhs, const MyStringFriend &rhs) {
    lhs = lhs + rhs; // using above '+' operator
    return lhs;
}

// repeat
MyStringFriend operator*(const MyStringFriend &lhs, int n) {
    MyStringFriend temp;

    for (int i{0}; i < n; ++i)
        temp = temp + lhs;

    return temp;
}

// repeat and assign
MyStringFriend operator*=(MyStringFriend &lhs, int n) {
    lhs = lhs * n;
    return lhs;
}

// output operator
std::ostream& operator<<(std::ostream &os, const MyStringFriend &rhs) {
    os << rhs.str;
    return os;
}

// input operator
std::istream& operator>>(std::istream &is, MyStringFriend &rhs) {
    char *buff = new char[1000];
    is >> buff;
    rhs = MyStringFriend{buff};
    delete [] buff;
    return is;
}

// Other functions
void MyStringFriend::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

int MyStringFriend::get_length() const { return (int) strlen(str); }

const char* MyStringFriend::get_str() const { return str; }
