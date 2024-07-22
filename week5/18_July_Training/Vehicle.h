#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include"VehicleType.h"
#include"VehicleStandard.h"
#include"VehicleFuelType.h"
#include"VehicleEngineType.h"
#include"VehicleMultimedia.h"

class Vehicle
{
private:
    VehicleType m_vehicle_type{VehicleType::PRIVATE};
    VehicleStandard m_vehicle_standard{VehicleStandard::BS4};
    VehicleFuelType m_vehicle_fuel_type{VehicleFuelType::ICE};
    VehicleEngineType m_vehicle_engine_type{VehicleEngineType::HYBRID};
    VehicleMultimedia m_vehicle_multimedia_type{VehicleMultimedia::ANALOG};
    float m_vehicle_price{0.0f};
public:
    Vehicle()=delete;
    ~Vehicle()=default;
    Vehicle(const Vehicle&)=delete;
    Vehicle& operator=(const Vehicle&)=delete;
    Vehicle(Vehicle&&)=delete;
    Vehicle& operator=(Vehicle&&)=delete;

    Vehicle(VehicleType vtype, VehicleStandard vstandard, VehicleFuelType vfueltype, VehicleEngineType venginetype, VehicleMultimedia vmultimediatype, float vprice);

    float CalculateRegistrationCost() const;

    VehicleType vehicleType() const { return m_vehicle_type; }

    VehicleStandard vehicleStandard() const { return m_vehicle_standard; }

    VehicleFuelType vehicleFuelType() const { return m_vehicle_fuel_type; }

    VehicleEngineType vehicleEngineType() const { return m_vehicle_engine_type; }

    VehicleMultimedia vehicleMultimediaType() const { return m_vehicle_multimedia_type; }

    float vehiclePrice() const { return m_vehicle_price; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
        

};

#endif // VEHICLE_H
