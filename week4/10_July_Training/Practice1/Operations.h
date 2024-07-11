#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Bike.h"
#include "Car.h"
#include<variant>
#include<list>
#include<thread>
#include<mutex>
#include<optional>
#include<future>

using VrType=std::variant<Car*,Bike*>;
using DataContainer=std::list<VrType>;
using ThreadContainer=std::list<std::thread>;

class Operations
{
private:
    static std::mutex mt;
    static DataContainer data;
    static ThreadContainer threads;
public:
    Operations()=delete;
    ~Operations()=default;
    Operations(const Operations&)=delete;
    Operations& operator=(const Operations&)=delete;
    Operations(Operations&&)=delete;
    Operations& operator=(Operations&&)=delete;

    static void CreateCarsAndObjects();

    static void FindAverageCost();

    static std::optional<VrType> ReturnMatchingInstanceId(std::string id);

    static void DisplayInsuranceAmount();

    static std::optional<unsigned short> FindseatCountForGivenId(std::string id);

    static void MapThreads();

    static void JoinThreads();

    static void Deallocate();
    
};

#endif // OPERATIONS_H
