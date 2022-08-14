#include "MyStringMember.hpp" // member functions
#include "MyStringFriend.hpp" // non-member functions

using
std::cout,
std::cin,
std::endl;

int main() {
    cout << std::boolalpha;
    MyStringFriend a{"alex"};
    MyStringFriend b{"Alex"};

    // comparison operators
    cout << (a == b) << endl; // false
    cout << (a != b) << endl; // true
    cout << (a < b) << endl; // false
    cout << (a > b) << endl; // true

    // lowercase
    MyStringFriend s1{"ALEX"};
    cout << s1 << endl;
    s1 = -s1; // Using Move Assignment
    cout << s1 << endl; // alex

    // Concat
    s1 = s1 + "*******"; // Using Move Assignment
    cout << s1 << endl; // alex*******

    // Concat and Assign
    s1 += "--------"; // Using Move Assignment, Using Copy Assignment
    cout << s1 << endl; // alex*******--------

    // Repeat
    MyStringFriend s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl; // 123451234512345

    // Repeat and Assign
    MyStringFriend s3{"abcdef"};
    s3 *= 5;
    cout << s3 << endl; // abcdefabcdefabcdefabcdefabcdef

    // Insertion
    MyStringFriend insert;
    cout << "Insert new MyStringMember: ";
    cin >> insert;
    cout << endl;

    // extraction
    cout << insert << endl;


    return 0;
}


