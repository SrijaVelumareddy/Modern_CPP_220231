#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "SmartDevice.h"
#include<functional>

using Predicate = std::function<bool(const SmartDevice*)>;
//a function which takes single input value and returns bool is called predicate

void CreateObjects(SmartDevice** devices, unsigned int size);

void Deallocate(const SmartDevice** devices, const unsigned int size);

void FindIthIndexValue(const SmartDevice* device, unsigned int idx);

void FindMaxGSTDeviceId(const SmartDevice** devices, unsigned int idx);

/*
        filter smart devices and display details of devices passing the filter criteria 
        Criteria is provided by the user

        example: show details of all the devices whose with price over 6000.0f
    */

void FilterDevices(Predicate fn, const SmartDevice** devices, const unsigned int size);

/*

                                                [  10.21  | 9.21  | 11.22 ]
                                                ^
                                                |
    [d101 |Mobile  | 9000.0f    |BLUETOOTH   |0x100H]
    24      24           4           4         8
*/



#endif // FUNCTIONALITIES_H
