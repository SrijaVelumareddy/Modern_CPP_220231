#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
#include "EngineType.h"

class Engine
{
private:
    std::string m_id{""};
    EngineType m_engine_type{};
    float m_engine_cc{0.0f};
    float m_engine_torque{0.0f};
    int m_engine_horsepower{0};

public:
    Engine()=delete;
    ~Engine()=default;
    Engine(const Engine&)=delete;
    Engine(Engine&&)=delete;
    Engine& operator=(const Engine&)=delete;
    Engine& operator=(Engine&&)=delete;

    Engine(std::string id, EngineType type, float enginecc, float etorque, int ehorsepower);

    std::string id() const { return m_id; }

    EngineType engineType() const { return m_engine_type; }

    float engineCc() const { return m_engine_cc; }

    float engineTorque() const { return m_engine_torque; }

    int engineHorsepower() const { return m_engine_horsepower; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);

};

#endif // ENGINE_H
