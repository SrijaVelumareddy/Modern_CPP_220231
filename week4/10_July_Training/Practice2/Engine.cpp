#include "Engine.h"

Engine::Engine(std::string id, EngineType type, float enginecc, float etorque, int ehorsepower)
    : m_id{id},m_engine_type{type},m_engine_cc{enginecc},m_engine_torque{etorque},m_engine_horsepower{ehorsepower}
    {}

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_engine_type: " <<(int)rhs.m_engine_type
           << " m_engine_cc: " << rhs.m_engine_cc
           << " m_engine_torque: " << rhs.m_engine_torque
           << " m_engine_horsepower: " << rhs.m_engine_horsepower;
        return os;
    }