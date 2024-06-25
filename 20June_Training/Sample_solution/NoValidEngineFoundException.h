#ifndef NOVALIDENGINEFOUNDEXCEPTION_H
#define NOVALIDENGINEFOUNDEXCEPTION_H

#include <stdexcept>

class NoValidEngineFoundException : public std::exception
{
private:
    std::string _msg;

public:
    NoValidEngineFoundException(std::string msg) : _msg{msg} {};
    NoValidEngineFoundException()=delete;
    NoValidEngineFoundException(const NoValidEngineFoundException& other)=delete;
    NoValidEngineFoundException(NoValidEngineFoundException&&)=default;
    NoValidEngineFoundException& operator=(const NoValidEngineFoundException& other) = delete;
    NoValidEngineFoundException& operator=(NoValidEngineFoundException&&) = default;
    ~NoValidEngineFoundException()=default;
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW 
    {
        return _msg.c_str();
    }
};

#endif // NOVALIDNoValidNoFoundExceptionFOUNDEXCEPTION_H
