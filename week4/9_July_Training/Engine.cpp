#include "Engine.h"

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_type: " << (int)rhs.m_type //or can use static_cast<int>
           << " m_engine_cc: " << rhs.m_engine_cc
           << " m_engine_torque: " << rhs.m_engine_torque
           << " m_engine_horsepower: " << rhs.m_engine_horsepower;
        return os;
}