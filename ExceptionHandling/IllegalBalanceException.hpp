#ifndef IllegalBalanceException_hpp
#define IllegalBalanceException_hpp

class IllegalBalanceException: public std::exception {
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;
    virtual const char* what() const noexcept {
        return "Illegal Balance Exception!";
    }
};

#endif /* IllegalBalanceException_hpp */
