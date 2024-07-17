#include<unordered_map>
#include<iostream>


//names of products attached to a numeric serial number for each

using Container=std::unordered_map<unsigned int, std::string>;

//iterator : idea of going one element to other without worrying about the actual process involved

//old cpp way
void DisplayMapUsingIterators(const Container& data){
    for(auto itr=data.begin(); itr!=data.end(); ++itr) {
        std::cout << "Key is : " << itr->first << " and value is : " << itr->second << "\n";
    }
}

//c++17
void DisplayMapUsingStructuredBinding(const Container& data){
    for( auto& [k,v] : data) { //syntactic sugar
        std::cout << "Key is : " << k << " and value is : " << v << "\n";
    }
}

//old way but different(cpp 11/14)
void DisplayMapUsingPair(const Container& data){
    for(const std::pair<unsigned int,std::string>& p : data){
        std::cout << "Key is : " << p.first << " and value is : " << p.second << "\n";
    }
}

int main()
{
    Container data{
        {101,"Steering Wheel"}, //pair of 1 key attached to 1 value
        {102,"Alloy Wheels"},
        {103,"Smart Mirror ORM"},
        {104,"360 Camera setup"}
    };

    DisplayMapUsingIterators(data);
    DisplayMapUsingStructuredBinding(data);
    DisplayMapUsingPair(data);
}