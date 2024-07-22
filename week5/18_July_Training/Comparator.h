//struct and class in C++ are exactly the same?

#ifndef COMPARATOR_H
#define COMPARATOR_H

#include<memory>
#include"Vehicle.h"

using VehiclePtr=std::shared_ptr<Vehicle>;
struct Comparator{
    bool operator()(const VehiclePtr& v1,const VehiclePtr& v2){
        return v1->vehiclePrice() < v2->vehiclePrice();
    }
    Comparator()=default;
    ~Comparator()=default;
};

#endif // COMPARATOR_H
