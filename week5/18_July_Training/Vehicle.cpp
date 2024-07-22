#include "Vehicle.h"

Vehicle::Vehicle(VehicleType vtype, VehicleStandard vstandard, VehicleFuelType vfueltype, VehicleEngineType venginetype, VehicleMultimedia vmultimediatype, float vprice) : m_vehicle_type{vtype}, m_vehicle_standard{vstandard}, m_vehicle_fuel_type{vfueltype}, m_vehicle_engine_type{venginetype}, m_vehicle_multimedia_type{vmultimediatype}, m_vehicle_price{vprice} 
{
    if(m_vehicle_fuel_type == VehicleFuelType::ALTERNATE_FUEL){
        m_vehicle_engine_type==VehicleEngineType::NA;
    }
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
        os << "m_vehicle_type: " << (int)rhs.m_vehicle_type
           << " m_vehicle_standard: " << (int)rhs.m_vehicle_standard
           << " m_vehicle_fuel_type: " << (int)rhs.m_vehicle_fuel_type
           << " m_vehicle_engine_type: " << (int)rhs.m_vehicle_engine_type
           << " m_vehicle_multimedia_type: " << (int)rhs.m_vehicle_multimedia_type
           << " m_vehicle_price: " << rhs.m_vehicle_price;
        return os;
    }

float Vehicle::CalculateRegistrationCost() const {
    float result=0.0f;
    if(m_vehicle_fuel_type==VehicleFuelType::ALTERNATE_FUEL || m_vehicle_fuel_type==VehicleFuelType::ICE){
        result= 0.10f * m_vehicle_price;
    }
    else {
        result= 0.20f * m_vehicle_price;
    }
    return result;
}