#include"Operations.h"
#include<future>

int main(){
    //step1: make objects
    Operations::CreateCarsAndBikes();

    //step2: Execute parallel functions
    Operations::MapThreads();
    Operations::JoinThreads();
    // Operations::FindAverageCost();

    //step3: serial functions
    //auto result1 = Operations::FindSeatCountForGivenId("c101"); or
    std::future<std::optional<unsigned int>>result1 = std::async(Operations::FindSeatCountForGivenId,"c101");
    std::future<std::optional<VrType>> result2 = std::async(Operations::ReturnMatchingInstance,"c101");

    std::optional<unsigned int> res1 = result1.get();
    std::optional<VrType> res2 = result2.get();

    if( res1.has_value()){
        std::cout << "Seat count for id is : " << res1.value() << "\n";
    }

    //auto result2 = Operations::ReturnMatchingInstance("c101"); OR
    
    if( res2.has_value()){
        std::cout << "Matching instance found : "<<"\n";
        std::visit ( [](auto&& val) { std::cout << *val << "\n";}, res2.value());
    }

    Operations::Deallocate();

}