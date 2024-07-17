#include "Operations.h"

//initializing static members of a class must be done in implementing files only not in .h files
// DataContainer Operations::m_data{};
// ThreadContainer Operations::m_threads{};
std::mutex mt {};

void CreateCarsAndBikes(DataContainer& data)
{
    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("c101"), //if you want perfect forwarding you can use forward as tuple or else tuple is enough
        std::forward_as_tuple(std::make_shared<Car>("c101",50000.0f,5))
    );

    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("b102"),
        std::forward_as_tuple(std::make_shared<Bike>("b102",25000.0f))
    );

    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("b103"),
        std::forward_as_tuple(std::make_shared<Bike>("b103",28000.0f))
    );

    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("c104"),
        std::forward_as_tuple(std::make_shared<Car>("c104",90000.0f,7))
    );

    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("c105"),
        std::forward_as_tuple(std::make_shared<Car>("c105",100000.0f,8))
    );


}

void FindAverageCost(const DataContainer& data)
{
    if(data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }

    float total {0.0f};

    for( auto& [k,v] : data) {
        std::visit ( [&](auto&& val) { total += val->price();},v); //total is outside the lambda function hence we used '&' in capture class to refer it.
    }

    if(!data.empty()) {
        mt.lock();
        std::cout << "Average cost is : " << total/data.size() << "\n";
        mt.unlock();
    }
}

std::optional<VrType> ReturnMatchingInstance(const DataContainer& data,const std::string id)
{
    if(data.empty()){
        //mt.lock();
        std::cerr << "Empty data container\n";
        //mt.unlock();
    }

    std::optional<VrType>result{std::nullopt}; 
    bool m_id_found {false}; 

    for( auto& [k,v] : data){
        std::visit ( [&] (auto&& val) { if(val->id() == id) { result=v; m_id_found=true;}},v);
        if(m_id_found){
            break;
        }
    }
    return result;
}

std::optional<unsigned int> FindSeatCountForGivenId(const DataContainer& data,const std::string id)
{
    if(data.empty()){
        // mt.lock();
        std::cerr << "Empty data container\n";
        // mt.unlock();
    }
    std::optional<unsigned int> result {std::nullopt};
    bool matchFound {false};

    for( auto& [k,v] : data){
        if(std::holds_alternative<CarPtr>(v)){ //condition to check that we need only car id
            CarPtr temp = std::get<0>(v); 
            if(temp->id() == id){
                matchFound=true;
                result=temp->seatCount();
            }
        }
    }
    if(!matchFound && !data.empty()){
        mt.lock();
        std::cerr << "Id not found\n";
        mt.unlock();
    }
    return result;

    // return ;
}

void DisplayInsuranceAmount(const DataContainer& data)
{
    if(data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }
    for(auto& [k,v] : data){
        std::visit ( [](auto&& val) {mt.lock(); std::cout << val->InsuranceAmount() << "\n"; mt.unlock();},v);
    }
}

void MapThreads(ThreadContainer& threads,const DataContainer& data)
{
    threads.emplace_back(FindAverageCost,std::ref(data));
    //m_threads.emplace_back( Operations::ReturnMatchingInstance,"c105" ); //this will not execute because threads will not return anything ie.std::cout cannot be used with threads
    threads.emplace_back(DisplayInsuranceAmount,std::ref(data));
    //m_threads.emplace_back( Operations::FindSeatCountForGivenId, "b101" ); //this will not execute because threads will not return anything ie.std::cout cannot be used with threads
}

void JoinThreads(ThreadContainer& threads)
{
    for(std::thread& th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}
