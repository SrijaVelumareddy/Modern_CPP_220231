#include<iostream>

enum class SensorType{
    TYRE_PRESSURE,
    FUEL_GAUGE
};

class SensorData
{
private:
    SensorType m_sensor_type; 
    float m_sensor_reading;
public:
    SensorData(SensorType stype,float value) : m_sensor_type{stype}, m_sensor_reading{value} {}
    ~SensorData() {}
    SensorData(const SensorData&)=delete;
    SensorData& operator=(const SensorData&)=delete;
    SensorData(SensorData&&)=default;
    SensorData& operator=(SensorData&&)=default;


    void setSensorReading(float sensor_reading) { m_sensor_reading = sensor_reading; }

};

/*
    1 sensor and set its value to 0
*/
void ResetSensor(SensorData& s){
    s.setSensorReading(0.0f);
}

/*
    takes 
*/
SensorData MakeNewSensor(){
    float val {0.0f};
    std::cin >> val;

    SensorData s1{SensorType::TYRE_PRESSURE,val};
}

int main(){
    SensorData s1{SensorType::FUEL_GAUGE,28.1};
    ResetSensor(s1);
}

/*
    Rule : how badly can opy impact your program?
        avoid copy at all costs unless your code cannot be written without copy

    Don't use copy until there is only one legitimate reason that is when you purposely replicate the data, modify it without modifying the original data. Except this case, disbale copy in all other situations
        - you can use call by reference, move constructor, copy elision
*/
    