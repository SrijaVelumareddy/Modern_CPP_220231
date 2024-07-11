#ifndef CAR_H
#define CAR_H

#include<iostream>

class Car
{
private:
    std::string m_id {""};
    float m_price {0.0f};
    unsigned short m_seat_count {0};
public:
    Car()=delete;
    ~Car()=default;
    Car(const Car&)=delete;
    Car(Car&&)=delete;
    Car& operator=(const Car&)=delete;
    Car& operator=(Car&&)=delete;

    Car(std::string id, float price, unsigned short seatcount);

    float InsuranceAmount(){
        return 0.2f * m_price;
    }

    std::string id() const { return m_id; }

    float price() const { return m_price; }

    unsigned short seatCount() const { return m_seat_count; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    

};

#endif // CAR_H
