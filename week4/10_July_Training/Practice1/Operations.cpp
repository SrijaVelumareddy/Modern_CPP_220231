#include "Operations.h"

DataContainer Operations::data{};
ThreadContainer Operations::threads{};
std::mutex Operations::mt{};

void Operations::CreateCarsAndObjects()
{
    data.emplace_back(new Car("c101",4000.0f,5));
    data.emplace_back(new Bike("b102", 3000.0f));
    data.emplace_back(new Bike("b103", 5600.0f));
    data.emplace_back(new Bike("b104", 3700.0f));
    data.emplace_back(new Car("c105",7400.0f,3));
    data.emplace_back(new Car("c106",8400.0f,8));

}

void Operations::FindAverageCost()
{
    if(data.empty()){
        std::lock_guard<std::mutex> lk(mt);
        std::cerr << "Empty data container\n";
    }
    float total {0.0f};
    for(const VrType v : data){
        std::visit([&](auto&& val){total+=val->price();},v);
    }
    if(!data.empty()){
        std::lock_guard<std::mutex> lk(mt);
        std::cout << "Average cost is : " << total/data.size() << "\n";
    }
    
}

std::optional<VrType> Operations::ReturnMatchingInstanceId(std::string id)
{
    if(data.empty()){
        std::cerr << "Empty data container\n";
    }
    std::optional<VrType>output{std::nullopt};
    bool match_found {false};
    for(const VrType v : data){
        std::visit([&](auto&& val){ if(val->id()==id) { output=v; match_found=true;} ;},v);
        if(match_found){
            break;
        }
    }
    return output;
}

void Operations::DisplayInsuranceAmount()
{
    if(data.empty()){
        std::cerr << "Empty data container\n";
    }
    for(const VrType v : data){
        std::visit([](auto&& val){ std::cout <<"Insurance amount is : " << val->InsuranceAmount() << "\n";},v);
    }
}

std::optional<unsigned short> Operations::FindseatCountForGivenId(std::string id)
{
    if(data.empty()){
        std::cerr << "Empty data container\n";
    }

    std::optional<unsigned short> output{std::nullopt};
    bool match_found{false};
    for(const VrType v : data){
        if(std::holds_alternative<Car*>(v)){
            Car* val=std::get<0>(v);
            output=val->seatCount();
            match_found=true;
        }
    }
    if(!data.empty() && !match_found){
        std::lock_guard<std::mutex> lk(mt);
        std::cout << "Id not found\n" << "\n";
    }
    return output;
    
}

void Operations::MapThreads()
{
    threads.emplace_back(Operations::FindAverageCost);
    threads.emplace_back(Operations::DisplayInsuranceAmount);
}

void Operations::JoinThreads()
{
    for(std::thread& th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}

void Operations::Deallocate()
{
    if(data.empty()){
        std::cerr << "Empty data container\n";
    }
    for(const VrType v : data){
        std::visit([](auto&& val){ delete val;},v);
    }
}
