#include "Car.h"

Car::Car(std::string id, float price, unsigned short seatcount) :
m_id{id},m_price{price},m_seat_count{seatcount} {}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_price: " << rhs.m_price
           << " m_seat_count: " << rhs.m_seat_count;
        return os;
    }