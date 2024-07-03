#include<iostream>
#include<vector>
#include<variant>

//variants are categorical types which allows "either" "or" principle of typing 

int main(){
    int32_t n1{100};
    std::string s1{"Srija"};
    std::variant<int32_t, std::string> vr;

    vr=n1; //n1 is assigned to variant

    std::cout << "Variant is working\n";

    vr=s1;
}

/* 
    vr=n1;
        int32_t       std::string          index_variable
    [   10        /    xxxxxxx         /      0          ] //24 byte


     vr=s1;
        int32_t       std::string          index_variable
    [   10        /     {Srija}         /       1         ] //24 byte

*/
//using variant, if you try to access a invalid location you get "bad variant exception"
//but when you use unions, you get "undefined behaviour", noexceptions, no errors