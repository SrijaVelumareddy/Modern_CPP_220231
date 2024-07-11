#include<iostream>
#include<variant>

using VrType = std::variant<int, std::string>;

//possible on all types of variant
void DisplayValue(VrType& v){
    std::visit( [](auto&& val){ std::cout << val << "\n";},v);//auto&& - forwarded references 
}

void ConvertToUpperCase(VrType& v){
    if(std::holds_alternative<std::string>(v)) //if you want to access one of the types in variant we use holds-alternative
    {
        //access the string from its slot
        std::string temp = std::get<1>(v);
        for(char& c : temp){
            std::cout << char( (int)c - 32);
        }
    }
}

int main(){

}