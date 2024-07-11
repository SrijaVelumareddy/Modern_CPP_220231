#include "Operations.h"

int main(){
    Operations::CreateCarsAndObjects();
    // Operations::FindAverageCost();
    // Operations::DisplayInsuranceAmount();
    Operations::MapThreads();
    Operations::JoinThreads();

    std::future<std::optional<VrType>>result1=std::async(Operations::ReturnMatchingInstanceId,"b102");
    std::optional<VrType>res1=result1.get();
    if(res1.has_value()){
        std::cout <<"Matching instance found : " << "\n";
        std::visit([](auto&& val){ std::cout << *val << "\n";},res1.value());
    }
    // std::optional<VrType>res1=Operations::ReturnMatchingInstanceId("b102");
    // if(res1.has_value()){
    //     std::cout <<"Matching instance found : " << "\n";
    //     std::visit([](auto&& val){ std::cout << *val << "\n";},res1.value());
    // }

    std::future<std::optional<unsigned short>>result2=std::async(Operations::FindseatCountForGivenId,"c105");
    std::optional<unsigned short>res2=result2.get();
    if(res2.has_value()){
        std::cout <<"Seat count for id is : " << res2.value() << "\n";
    }

    Operations::Deallocate();
}