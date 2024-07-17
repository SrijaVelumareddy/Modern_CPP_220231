#include"Operations.h"



int main(){
    DataContainer data{};
    ThreadContainer threads{};
    //step1: make objects
    CreateCarsAndBikes(data);

    //step2: Execute parallel functions
    MapThreads(threads,data);
    JoinThreads(threads);
    // Operations::FindAverageCost();

    //step3: serial functions
    //auto result1 = Operations::FindSeatCountForGivenId("c101"); or
    std::future<std::optional<unsigned int>>result1 = std::async(&FindSeatCountForGivenId,std::ref(data),"c101");
    std::optional<unsigned int> res1 = result1.get();
    if( res1.has_value()){
        std::cout << "Seat count for id is : " << res1.value() << "\n";
    }

    //auto result2 = Operations::ReturnMatchingInstance("c101"); OR
    std::future<std::optional<VrType>>result2 = std::async(&ReturnMatchingInstance,std::ref(data),"b102");
    std::optional<VrType> res2 = result2.get();
    if( res2.has_value()){
        std::cout << "Matching instance found : "<<"\n";
        std::visit ( [](auto&& val) { std::cout << *val << "\n";}, res2.value());
    }

    //Deallocate(data);

}