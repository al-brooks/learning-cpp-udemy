
#ifndef InsufficientFundsException_hpp
#define InsufficientFundsException_hpp

class InsufficientFundsException: public std::exception {
public:
    InsufficientFundsException() noexcept = default;
    ~InsufficientFundsException() = default;
    virtual const char* what() const noexcept {
        return "Insufficent Funds Exception!";
    }
};

#endif /* InsufficientFundsException_hpp */
