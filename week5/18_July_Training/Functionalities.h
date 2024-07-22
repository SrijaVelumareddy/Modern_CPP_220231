#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"
#include<memory>
#include<vector>
#include<future>
#include<optional>
#include<unordered_set>
#include<queue>
#include<thread>
#include<mutex>
#include<numeric>
#include<functional>
#include<algorithm>
#include"Comparator.h"

using VehiclePtr=std::shared_ptr<Vehicle>;
using DataContainer=std::vector<VehiclePtr>;
using Predicate=std::function<bool(const VehiclePtr&)>;
using PriorityQueue=std::priority_queue<VehiclePtr,DataContainer,Comparator>;


/*
    This function creates data for demonstration purposes in a vector using shared pointer
*/
void CreateVehicleObjects(DataContainer& vehicles);


// PriorityQueue MaximumVehicleprice(DataContainer& vehicles,const Predicate fn);
/*
    This function uses Comparator type(a struct with overload () operator) to compare and prioritize vehiclePtr type values in the input data
*/
PriorityQueue PrioritizeVehicles(const DataContainer& vehicles);


// Datacontainer ReturnUniqueObjects(const DataContainer& vehicles);


// unsigned int CountOfMatchingEngineTypeObjects(DataContainer& vehicles);
/*
    Returns the count of vehicle whose type matches with caller's function
*/
std::optional<std::size_t> CountOfMatchingEngineTypeObjects(const DataContainer& vehicles,const VehicleEngineType venginetype);


// bool ReturnMatchingInstances(DataContainer& vehicles, Predicate predicate_fn);
/*
    Return a container of all vehicle smart pointers that satisfy the input predicate
*/
std::optional<DataContainer> ReturnMatchingVehicles(const DataContainer& vehicles, const Predicate fn);


// bool CheckPriceOfVehicles(DataContainer& vehicles, Predicate fn);
/*
    return true or false to indicate whether all vehicles have price above 90K
*/
bool AreAllVehiclesPriceAbove90K(const DataContainer& vehicles);


/*
    Return the average of CalculateRegistrationCost function called on each object in the container
*/
float AverageRegistrationCost(const DataContainer& vehicles);


/*
    Return a container of last N vehicles from the input data
*/
std::optional<DataContainer> ReturnLastNObjects(const DataContainer& vehicles,unsigned int N);


/*
    function for applying hash on input value for unordered set
*/
std::size_t hash_logic(const VehiclePtr& v){
    return std::hash<VehicleMultimedia>() ( v->vehicleMultimediaType() );
}


/*
    we are creating a new variable "comparision_fn"
*/
extern std::function<bool(const VehiclePtr& v1,const VehiclePtr& v2)>comparision_fn;
extern std::function<std::size_t(const VehiclePtr& v)> hash_lambda;


using UniqueVehicles=std::unordered_set<VehiclePtr, decltype(hash_lambda), decltype(comparision_fn)>;
/*
    This function creates and returns an unordered_set of unique multimedia type objects from my input
*/
std::optional<UniqueVehicles> FindUniqueVehicles(const DataContainer& vehicles);

#endif // FUNCTIONALITIES_H
