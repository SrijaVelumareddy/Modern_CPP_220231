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
#include "Car.h"
#include "Bike.h"

using VrType=std::variant<Car*,Bike*>;
using DataContainer=std::list<VrType>;
using ThreadContainer=std::list<std::thread>;

class Operations
{
private:
    static std::mutex mt;
    static DataContainer m_data;
    static ThreadContainer m_threads;
public:
    Operations()=delete;
    ~Operations()=default;
    Operations(const Operations&)=delete;
    Operations(Operations&&)=delete;
    Operations& operator=(const Operations&)=delete;
    Operations& operator=(Operations&&)=delete;

    static void CreateCarsAndBikes();

    /*
        FindAverageCost : Use visit function to do this. Both Car and Bike have a m_price attributor. We can use thier getter function to calculate total
    */
    static void FindAverageCost();

    /*
        ReturnMatchingInstance : Variant whose ID matches with id passed
    */
    static std::optional<VrType>ReturnMatchingInstance(std::string id);
    //may or may not returns a value hence we use optional instead od exception

    static void DisplayInsuranceAmount();

    static std::optional<unsigned int>FindSeatCountForGivenId(std::string id);

    static void Deallocate();
    /*
        Scenario1: id found, matches with a car, return seatcount
        Scenario1: id found, matches with bike ---> nullopt
        Scenario3: id not found : nullopt can be used but differentiation is not possible between scenario 2 and 3. In simple way, use flag variable and print a message along with nullopt.
    */

    /*
        Mapthreads: Attach a thread to a functionality
    */
    static void MapThreads();
    /*
        Jointhreads: Blocking main for respective functions executing in threads
    */
    static void JoinThreads();
};

#endif // OPERATIONS_H
