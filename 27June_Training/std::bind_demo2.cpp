/*
    std::bind allows to "refactor"/"repurpose"/"remodel" an existing function to create "partially-implemented" functions

    It can redirect the parameters of a function even if they are not provided in the sequence given.
    Another usecase of bind is it can hardcode or set few parameters fixed.
*/

/*
    cp    -r     source     destination

    strcpy(destination,source)

    g(x) is a partial function implemented on f(x,y) where y is 4  
*/

#include<iostream>
#include<functional>

int main(){
    auto fn = [](int32_t number, int32_t factor) { return number * factor;};

    //while binding lambda functions, don't use & symbol for function name bcz it will return object's address and not function's address and it will cause compile-time error.
    auto partially_implemented_fn = std::bind( fn,100, std::placeholders::_1 );
    partially_implemented_fn(20); //fn(100,20)
    partially_implemented_fn(20,1,2,3,4,5,6,7); //fn(100,20); //all other inputs are discarded
}