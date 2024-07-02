/*
    std::function wrapper
*/

#include<functional> //header file for functional programming
#include<vector>
#include<iostream>

using Logic=std::function<void (int32_t)>;
using DataContainer = std::vector<int32_t>;

void Adaptor(Logic fn, DataContainer& data){
    for(int32_t val : data){
        fn(val);
    }
}
int main(){
    DataContainer data{1,2,3};
    auto fn=[](int32_t number){
        std::cout << number * number * number << "\n";
    };
    Adaptor(fn,data);
    Adaptor(
        [](int32_t number) {std::cout << number * 100 << "\n";},
        data
    );

    Adaptor(
        //logic,
        [](int32_t number) {std::cout << number * 0.1f << "\n";},
        data
    );

}