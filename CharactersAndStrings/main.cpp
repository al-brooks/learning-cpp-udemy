#include <iostream>
#include <string>

using
std::cin,
std::getline,
std::cout,
std::endl,
std::string;

int main()
{
    // Provided Code:
    string alphabet {"-!*'%,[ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"!-'*,% [XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    // Ask the user for message
    string message{};
    cout << "Hi there, please enter the message you wish to be encrypted:" << endl;
    getline(cin, message);
    
    cout << "\nEncrypting Message.... " << endl;
    
    
    for(size_t i{0}; i < message.length(); ++i) {
        size_t pos = alphabet.find(message[i]);
        if(pos != string::npos){
            message[i] = key[pos];
        } else
            continue;
    }
    
    cout << message << endl;
    
    cout << "\n------------------------------------------"<< endl;
    
    cout << "\nDecrypting Message.... " << endl;
    
    for(size_t i{0}; i < message.length(); ++i) {
        size_t pos = key.find(message[i]);
        if(pos != string::npos) {
            message[i] = alphabet[pos];
        } else
            continue;
    }
    
    cout << message << endl;
    
    cout << endl;
    return 0;
}
