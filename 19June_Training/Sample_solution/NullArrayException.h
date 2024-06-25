#include <iostream>

class NullArrayException : public std::exception
{
private:
    std::string m_msg;
public:
    NullArrayException(std::string msg) {
        m_msg=msg;
    }
    ~NullArrayException() {}
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW 
    {
        return m_msg.c_str();
    }
};