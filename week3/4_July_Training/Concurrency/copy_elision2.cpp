#include<iostream>

class Data
{
private:
    int m_value{0};
public:
    Data()=default;
    ~Data()=default;
    Data(const Data&)=delete;
    Data(Data&&)=delete;
    Data& operator=(const Data&)=delete;
    Data& operator=(Data&&)=delete;

    explicit Data(int val) : m_value{val} {}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }

};

// Data Magic(){
//     return Data {100};
// }

// int main(){
//     Data d1 = Magic(); //this is initialization
//     //an object is initialized by return value of magic function
// }


// Data Magic(){
//     Data obj {100};
//     return obj; //this will work when you enable move constructor instead of copy
// }
// int main(){
//     Data d1 = Data {100};
// }