#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <stdexcept>

class IdNotFoundException : public std::exception

{
private:
    std::string _msg;
public:
    IdNotFoundException(std::string m) {
        this->_msg = m;
    }
    ~IdNotFoundException() {}

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();//c_str function coverts string data into char pointer
    }

};

#endif // IDNOTFOUNDEXCEPTION_H
