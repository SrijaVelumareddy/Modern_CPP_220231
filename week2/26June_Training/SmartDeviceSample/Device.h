#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>

class Device
{
private:
    std::string _id;
    std::string _modelName;
    float _price;

public:
    Device(std::string id, std::string name, float price);
    virtual ~Device();

    virtual float CalculateGstCost() const = 0;

    std::string id() const { return _id; }

    float price() const { return _price; }

    friend std::ostream &operator<<(std::ostream &os, const Device &rhs) {
        os << "_id: " << rhs._id << "\n"
           << " _modelName: " << rhs._modelName << "\n"
           << " _price: " << rhs._price << "\n";
        return os;
    }

    
};

#endif // DEVICE_H
