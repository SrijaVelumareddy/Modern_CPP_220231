#include "Operations.h"

//initializing static members of a class must be done in implementing files only not in .h files
DataContainer Operations::m_data{};
ThreadContainer Operations::m_threads{};
std::mutex Operations::mt {};

void Operations::CreateCarsAndBikes()
{
    m_data.emplace_back(new Car("c101",50000.0f,5));
    m_data.emplace_back(new Bike("b102",25000.0f));
    m_data.emplace_back(new Bike("b103",28000.0f));
    m_data.emplace_back(new Car("c104",90000.0f,7));
    m_data.emplace_back(new Car("c105",100000.0f,8));
    //m_data.emplace_back(nullptr);

}

void Operations::FindAverageCost()
{
    if(m_data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }

    float total {0.0f};

    for(const VrType v : m_data) {
        std::visit ( [&](auto&& val) { total += val->price();},v); //total is outside the lambda function hence we used '&' in capture class to refer it.
    }

    if(!m_data.empty()) {
        mt.lock();
        std::cout << "Average cost is : " << total/m_data.size() << "\n";
        mt.unlock();
    }
}

std::optional<VrType> Operations::ReturnMatchingInstance(std::string id)
{
    if(m_data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }

    std::optional<VrType>result{std::nullopt}; 
    bool m_id_found {false}; 

    for(const VrType v : m_data){
        std::visit ( [&] (auto&& val) { if(val->id() == id) { result=v; m_id_found=true;}},v);
        if(m_id_found){
            break;
        }
    }
    return result;
}

std::optional<unsigned int> Operations::FindSeatCountForGivenId(std::string id)
{
    if(m_data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }
    std::optional<unsigned int> result {std::nullopt};
    bool matchFound {false};

    for(const VrType v : m_data){
        if(std::holds_alternative<Car*>(v)){ //condition to check that we need only car id
            Car* temp = std::get<0>(v); 
            if(temp->id() == id){
                matchFound=true;
                result=temp->seatCount();
            }
        }
    }
    if(!matchFound && !m_data.empty()){
        mt.lock();
        std::cerr << "Id not found\n";
        mt.unlock();
    }
    return result;

    // return ;
}

void Operations::DisplayInsuranceAmount()
{
    if(m_data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }
    for(const VrType v : m_data){
        std::visit ( [](auto&& val) {mt.lock(); std::cout << val->InsuranceAmount() << "\n"; mt.unlock();},v);
    }
}

void Operations::MapThreads()
{
    m_threads.emplace_back( Operations::FindAverageCost );
    //m_threads.emplace_back( Operations::ReturnMatchingInstance,"c105" ); //this will not execute because threads will not return anything ie.std::cout cannot be used with threads
    m_threads.emplace_back( Operations::DisplayInsuranceAmount );
    //m_threads.emplace_back( Operations::FindSeatCountForGivenId, "b101" ); //this will not execute because threads will not return anything ie.std::cout cannot be used with threads
}

void Operations::JoinThreads()
{
    for(std::thread& th : m_threads){
        if(th.joinable()){
            th.join();
        }
    }
}

void Operations::Deallocate()
{
    if(m_data.empty()){
        std::cerr << "Empty data container\n";
    }
    for(const VrType v : m_data) {
        std::visit ( [](auto&& val) { delete val;},v);
    }

}
