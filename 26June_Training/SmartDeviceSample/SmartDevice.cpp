#include "SmartDevice.h"

SmartDevice::SmartDevice(std::string id, std::string name, float price, Technology tech, float *arr)
    : Device(id, name, price)
{
    this->_deviceTechnology = tech;
    this->_arr = arr;
}

float SmartDevice::CalculateGstCost() const
{
    float result = 0.0f;
    if (_deviceTechnology == Technology::BLUETOOTH) {
        result = 0.1f * price();
    }

    else if (_deviceTechnology == Technology::BLUETOOTH_WIFI || _deviceTechnology == Technology::WIFI) {
        result = 0.15f * price();
    }

    else {
        result = 0.2f * price();
    }
    
    return result;
}

SmartDevice::~SmartDevice()
{
    std::cout << "Smart device destructor for ID: " << id() << " is called\n";
}

std::ostream &operator<<(std::ostream &os, const SmartDevice &rhs) {
    os << static_cast<const Device &>(rhs)
       << " _deviceTechnology: " << rhs._deviceTechnology
       << " _arr: " << rhs._arr;
    return os;
}


float SmartDevice::operator[](unsigned int idx) const {
        return this->_arr[idx];
    }