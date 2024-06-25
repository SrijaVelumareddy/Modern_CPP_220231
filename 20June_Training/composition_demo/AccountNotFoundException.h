#ifndef ACCOUNTNOTFOUNDEXCEPTION_H
#define ACCOUNTNOTFOUNDEXCEPTION_H

#include <iostream>

class AccountNotFoundException : public std::exception
{
private:
    std::string _msg;
public:
    AccountNotFoundException(std::string msg) {
        this->_msg = msg;
    }

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
        return _msg.c_str();
    }
    
    ~AccountNotFoundException() {}
};

#endif // ACCOUNTNOTFOUNDEXCEPTION_H
