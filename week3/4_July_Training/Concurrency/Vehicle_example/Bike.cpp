#include "Bike.h"


float Bike::InsuranceAmount() 
{ 
    return 0.1f * m_price;
};

 std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_price: " << rhs.m_price;
        return os;
    }
