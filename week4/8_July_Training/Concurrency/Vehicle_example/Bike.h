#ifndef BIKE_H
#define BIKE_H

#include<iostream>

class Bike
{
private:
    std::string m_id {""};
    float m_price {0.0f};
public:

    float InsuranceAmount() ;
    Bike()=delete;
    ~Bike()=default;
    Bike(const Bike&)=delete;
    Bike(Bike&&)=delete;
    Bike& operator=(const Bike&)=delete;
    Bike& operator=(Bike&&)=delete;

    Bike(std::string id, float price) : m_id{id},m_price{price} {}

    std::string id() const { return m_id; }
    void setId(const std::string &id) { m_id = id; }

    float price() const { return m_price; }
    void setPrice(float price) { m_price = price; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);
    
    
};

#endif // BIKE_H
