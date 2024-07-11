#include "Bike.h"

Bike::Bike(std::string id, float price) : m_id{id}, m_price{price} {}

std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_price: " << rhs.m_price;
        return os;
    }

