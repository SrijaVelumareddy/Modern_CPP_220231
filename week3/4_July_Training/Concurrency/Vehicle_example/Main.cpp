#include"Operations.h"

int main(){
    //step1: make objects
    Operations::CreateCarsAndBikes();

    //step2: Execute parallel functions
    Operations::MapThreads();
    Operations::JoinThreads();
    // Operations::FindAverageCost();

    //step3: serial functions
    //auto result1 = Operations::FindSeatCountForGivenId("c101"); or
    std::optional<unsigned int>result1 = Operations::FindSeatCountForGivenId("c101");

    if( result1.has_value()){
        std::cout << "Seat count for id is : " << result1.value() << "\n";
    }

    //auto result2 = Operations::ReturnMatchingInstance("c101"); OR
    std::optional<VrType> result2 = Operations::ReturnMatchingInstance("c101");
    if( result2.has_value()){
        std::cout << "Matching instance found : "<<"\n";
        std::visit ( [](auto&& val) { std::cout << *val << "\n";}, result2.value());
    }

    Operations::Deallocate();

}