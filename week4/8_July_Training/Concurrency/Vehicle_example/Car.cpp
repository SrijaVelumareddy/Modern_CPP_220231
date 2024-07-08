#include "Car.h"

float Car::InsuranceAmount() 
{ 
    return 0.2f * m_price;
};

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_price: " << rhs.m_price
           << " m_seat_count: " << rhs.m_seat_count;
        return os;
    }