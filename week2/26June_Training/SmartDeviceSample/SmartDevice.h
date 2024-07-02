#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include "Technology.h"
#include "Device.h"
#include <ostream>

class SmartDevice : public Device
{
private:
    Technology _deviceTechnology;
    float* _arr;
public:
    SmartDevice(std::string id, std::string name, float price, Technology tech, float* arr);

    float CalculateGstCost() const ;

    ~SmartDevice();

    float* arr() const { return _arr; }

    float operator[](unsigned int idx) const ;

    Technology deviceTechnology() const { return _deviceTechnology; }

    friend std::ostream &operator<<(std::ostream &os, const SmartDevice &rhs);
    

};

#endif // SMARTDEVICE_H
