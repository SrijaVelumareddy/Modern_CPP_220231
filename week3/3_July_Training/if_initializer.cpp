/*
    bool definition fn(){
    /////////
    }

    main(){
        bool flag fn();

        if(flag){
            /////
        } 
        else{
            ///////
        } //flag should be erased at the end of else line!

        //flag is gone
    }

*/
#include<iostream>

bool CheckDivisibilityBy3(int32_t number){
    return number % 3 == 0;
}

int main(){
    int32_t n1 {10};
    //if flag is initialized and flag is also true
    if(  bool flag = CheckDivisibilityBy3(n1); flag) {
        std::cout << "number is divisible by 3";
    }
    else {
        std::cerr << "Flag is set at : " << std::boolalpha<<flag<<"\nNumber is not divisible\n";
    }
    //std::cout << "cannot access flag now: "<< flag; //flag is not accessible and shows error
}