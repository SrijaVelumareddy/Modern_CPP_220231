/*
    1) CreateCarsAndOperationss
    2) FindAverageCostOfVehicles : print the average price of all vehicles in our database
    3) ReturnMatchingInstance : return the first vehicle whose id matches with the id parameter received
    4) Deallocation : release heap allocations if any!
    5) DisplayInsuranceAmount : show output of InsuranceAmount function for each instance
    6) FindSeatCountForGivenID : fetches vehicle based on ID and returns corresponding seat_count  
*/

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include<variant>
#include<optional>
#include<list>
#include<iostream>
#include<thread>
#include<mutex>
#include<unordered_map>
#include<future>
#include "Car.h"
#include "Bike.h"

using CarPtr=std::shared_ptr<Car>;
using BikePtr=std::shared_ptr<Bike>;
using VrType=std::variant<CarPtr,BikePtr>;
//using VrType=std::variant<std::shared_ptr<Car>,std::shared_ptr<Bike>>;
//using DataContainer=std::list<VrType>;
using DataContainer=std::unordered_map<std::string,VrType>;
using ThreadContainer=std::list<std::thread>;


void CreateCarsAndBikes(DataContainer& data);
void FindAverageCost(const DataContainer& data);
std::optional<VrType>ReturnMatchingInstance(const DataContainer& data,std::string id);
void DisplayInsuranceAmount(const DataContainer& data);
std::optional<unsigned int>FindSeatCountForGivenId(const DataContainer& data,std::string id);
//void Deallocate(DataContainer& data);
void MapThreads(ThreadContainer& threads,const DataContainer& data);
void JoinThreads(ThreadContainer& threads);


#endif // OPERATIONS_H
