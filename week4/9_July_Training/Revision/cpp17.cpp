#include<iostream>
#include<variant>
#include<optional>
#include<array>

float findaverage(std::array<int,3>& arr){
    float total {0.0f};
    for(int val : arr){
        total+=val;
    }
    return total/arr.size();
}

std::optional<int>FindFirstDivisibleBy10(std::array<int,3>&arr){
    for(int val : arr){
        if(val % 10 == 0){
            return val;
        }
    }
    return std::nullopt;
}
int main(){
    std::array<int,3> arr{10,20,30}; //n1=10, n2=20,n3=30

    //structured binding : destructure a container of fixed size items into seperate items

    auto [n1,n2,n3] = arr;

    //callfindaverage : if average is above 10, print it, else print a cerr message

    if( float ans = findaverage(arr); ans > 10 ) {
        std::cout << ans << "\n";
    }
    else {
        std::cerr << "Average is too low\n";
    }

    //optional return
    std::optional<float> result = FindFirstDivisibleBy10(arr);
    if(result.has_value()){
        std::cout << result.value();
    }
    else {
        std::cerr << "No number divisible by 10";
    }
 }