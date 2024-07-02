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

void formula(int x,int y,int z){
    std::cout << (x+y)-z << "\n";
}

int main(){
    formula(10,20,30);//0
    formula(20,30,10);//40
    auto partial_formula = std::bind(&formula, 100, std::placeholders::_1, std::placeholders::_2);//set x to 100 using bind
    //placeholders is something compiler says that particular place is reserved for something and we can give the number like first,second...
    partial_formula(10,90); //formula(100,10,90)

    auto swapped_formula=std::bind(&formula,std::placeholders::_2,std::placeholders::_3,std::placeholders::_1);

    swapped_formula(10,20,30);//formula(20,30,10)

    auto wierdly_mapped_function = std::bind(&formula, 100, 200, std::placeholders::_2);

    wierdly_mapped_function(99,10);//99 is discarded because _1 was not used
}