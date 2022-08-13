#include "MyStringMember.hpp" // member functions

using
std::cout,
std::cin,
std::endl;

int main() {
    cout << std::boolalpha;
    MyStringMember a{"alex"};
    MyStringMember b{"Alex"};

    // comparison operators
    cout << (a == b) << endl; // false
    cout << (a != b) << endl; // true
    cout << (a < b) << endl; // false
    cout << (a > b) << endl; // true

    // lowercase
    MyStringMember s1{"ALEX"};
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
    MyStringMember s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl; // 123451234512345

    // Repeat and Assign
    MyStringMember s3{"abcdef"};
    s3 *= 5;
    cout << s3 << endl; // abcdefabcdefabcdefabcdefabcdef

    // Insertion
    MyStringMember insert;
    cout << "Insert new MyStringMember: ";
    cin >> insert;
    cout << endl;

    // extraction
    cout << insert << endl;


    return 0;
}


