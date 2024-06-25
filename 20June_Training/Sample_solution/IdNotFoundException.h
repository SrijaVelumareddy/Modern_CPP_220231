#ifndef IdNotFoundException_H
#define IdNotFoundException_H

#include <stdexcept>

class IdNotFoundException : public std::exception
{
private:
    std::string _msg;

public:
    IdNotFoundException(std::string msg) : _msg{msg} {};
    IdNotFoundException()=delete;
    IdNotFoundException(const IdNotFoundException& other)=delete;
    IdNotFoundException(IdNotFoundException&&)=default;
    IdNotFoundException& operator=(const IdNotFoundException& other) = delete;
    IdNotFoundException& operator=(IdNotFoundException&&) = default;
    ~IdNotFoundException()=default;
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW 
    {
        return _msg.c_str();
    }
};

#endif
