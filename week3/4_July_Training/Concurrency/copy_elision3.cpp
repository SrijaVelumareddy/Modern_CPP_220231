#include<iostream>

class Data
{
private:
    int m_value{0};
public:
    Data()=default;
    ~Data()=default;
    Data(const Data&)=delete;
    Data(Data&&)=default;
    Data& operator=(const Data&)=delete;
    Data& operator=(Data&&)=delete;

    explicit Data(int val) : m_value{val} {}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }

};

Data Creator(){
    return Data {100};
}

// void Absorber(Data d1){
//     std::cout << d1 << "\n";
// }

// int main(){
//     Absorber ( Creator() ); //fn inside a function- first inner function will be called. This line becomes..
// }

Data Absorber(Data d1){
    std::cout << d1 << "\n";
    return d1;
}

int main(){
    Data obj=Absorber ( Data{100} ); //here any how we want an obj to be created and its value has to be printed then instead of creating obj in absorber and then copying into main, the cpp17 compiler creates in main itself so that it avoids copying. the compiler is like i will give an obj and print the value but don't ask how i do it.
    
    std::cout << "Object is in main: "<< obj << "\n";
}