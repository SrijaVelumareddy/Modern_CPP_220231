#include "Employee.h"
#include "BusinessOwner.h"

#include<variant>

using VrType=std::variant<BusinessOwner,Employee>;

void Display(const  VrType& v){
    // if( std::get<0>(v)){

    // }


//    try{
//     BusinessOwner& b std::get<0>(v);
//     std::cout << b << "\n";
//    }

    std::visit( [](auto&& val) { std::cout << val << "\n";}, v);

}

int main(){

    //In this method we need to enable the copy constructor and copy operator to be enabled because we are creating in the stack and it takes the data. Or else the code will not work.

    VrType vr;
    Employee e1 {"Srija", 9000.0f};
    BusinessOwner b1 {"Velumareddy", 89000.0f};
    vr = e1;
    Display(vr);

    vr=b1; //changed vr to take businessowner
    Display(vr);

}