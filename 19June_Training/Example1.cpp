#include <iostream>
#include <vector>

enum class Rating{
    _5_STAR,
    _4_STAR,
    _3_STAR,
    _2_STAR,
    _1_STAR,
    _NO_RATING
};

class Car
{
private:
    unsigned int m_id {0};
    float m_price {0.0f};
    Rating m_safetyRating {Rating::_NO_RATING};
public:
    Car(unsigned int id) : m_id {id} {}

    Car(unsigned int id, float price)
        : m_id {id}, m_price {price} {

        }
    Car(unsigned int id, float price, Rating rating)
        //: m_id {id}, m_price {price} , m_safetyRating{rating} {}
        : Car(id,price){
            m_safetyRating=rating;
        }
    Car()=delete;
    Car(const Car&) = default;
    Car& operator=(const Car&) = delete;
    Car& operator=(Car&&) = delete;
    Car(Car&&) = delete;
    ~Car() {}
};

int main(){
    //Car c1(101, 10000.0f, Rating::_4_STAR);
    //Car c2(102, 10000.0f, Rating::_3_STAR);

    //std::vector<Car> cars {c1,c2};

    //option1: Enable copy constructor

    //option2: moving cars is not applicable in this context

    //option3: Create data inside the vector directly (emplacing)-modern c++ feature
    std::vector<Car>cars;
    cars.emplace_back(101, 10000.0f, Rating::_4_STAR);
    cars.emplace_back(102, 10000.0f, Rating::_3_STAR);

    std::cout << "The number of elements in the vector currently: "<< cars.size();


    //int32_t n1=10; //32 bit/4 bytes memory for integer
    //int16_t n2=20; //16 bit/2 bytes memory for integer

}