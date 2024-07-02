#include "Device.h"

Device::Device(std::string id, std::string name, float price)
{
    this->_id = id;
    this->_modelName = name;
    this-> _price = price;
}

Device::~Device()
{
    std::cout << "Id " << _id << " Device destroyed\n";
}
