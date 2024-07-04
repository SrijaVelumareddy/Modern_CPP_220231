/*
    elision: not do something, not perform something, ignore/avoid something

    Guaranteed Copy Elision : cpp17
*/
#include<iostream>

class Data
{
private:
    int m_value{0};
public:
    Data()=default;
    ~Data()=default;
    Data(const Data&)=default;
    Data(Data&&)=delete;
    Data& operator=(const Data&)=delete;
    Data& operator=(Data&&)=delete;

    explicit Data(int val) : m_value{val} {}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }

};

void Magic(Data d1){
    std::cout << d1 << "\n";
}

// int main(){
//     Data d1{};
//     Magic(10); //constructor converts int to data object so this code works through implicit conversion. To avoid that conversion, make the constructor explicit and it blocks the type conversions. Now it gives error.

// }

// int main(){
//     Data d1 {100};
//     Magic {d1}; //error because copy constructor is disabled. To remove the error one way is to enable the copy constructor
// }

int main(){
    Magic(   Data {100}   ); //code is valid 
}

int main(){

    Data d1{11};
    Magic(d1); //this will not work because copy is disabled
    //Magic(88); //this will not work because conversion is disabled (explicit)
    Magic(   Data {100}   ); //an rvalue of type data is used to initialize an object of type data.
                            //compiler simply refactors/modifies the code as Data d1{100}
}