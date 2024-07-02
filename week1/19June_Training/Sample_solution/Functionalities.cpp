#include "Functionalities.h"

//whatever you write in emplace back, it should be "sufficient material"
//to make a new instance for the container of that specific type

//emplace back is used to insert a new element in to a vector container and is added at the end of the vector

//type: vector of type Engine pointers---> we need materials to make a new Engine*
void CreateObjects(std::vector<Engine*>& engines)
{
    engines.emplace_back(new Engine(101,234,56.3f));
    engines.emplace_back(new Engine(102,456,65.3f));
    engines.emplace_back(new Engine(103,678,47.3f));
    engines.emplace_back(nullptr);
}

int AverageHorsePower(const std::vector<Engine*>& engines)
{
    float total {0.0f};
    std::size_t validPointerCount {0};
    
    //range-based for loop (for each loop)
    /*
        for each const Engine pointer "called e" present in engines
    */
    for( const Engine* e : engines){
        if(e){
            total += e->horsepower();
            validPointerCount++;
        }
    }
    // for(std::size_t i=0;i<engines.size();i++){
    //     if(engines[i]){
    //         validPointerCount++;
    //         total += engines[i]->horsepower();
    //     }
    // if(validPointerCount == 0){
    //     throw NoValidEngineFoundException("All pointers are invalid\n");
    // }
        
    //}
    return total/validPointerCount;
}

float FindTorqueById(const std::vector<Engine*>& engines, unsigned int id)
{
    bool atleastOneValidPointerFound {false};
    for(const Engine* e : engines){
        if(e){
            atleastOneValidPointerFound=true;
            if(e->id() == id){
            return e->torque();
        }
    }
    }
    if(!atleastOneValidPointerFound){
        throw NoValidEngineFoundException("No valid engines present in data. Search cannot be formed\n");
    }
    throw IdNotFoundException("Match was not found\n");
}

int FindHorsePowerForMinTorqueEngine(const std::vector<Engine*>& engines)
{
    bool atleastOneValidPointerFound {false};
    float currentMinTorque {engines[0]->torque()};
    std::size_t indexOfMinTorque {0};
    std::size_t k=0;

    for(const Engine* e : engines){
        if(e) {
            atleastOneValidPointerFound = true;

            if(e->torque() < currentMinTorque){
                currentMinTorque = e->torque();
                indexOfMinTorque = k;
            }
        }
        k++;
    }
    
}

/*
    Think about inputs to a function

    Think about 1 sure-shot way of completing the function and getting a valid output

    Now, start thinking of all possible ways, functions may not be completed based on inputs provided and system situations

*/