#include<unordered_map>
#include<iostream>

#include "Employee.h"
#include<functional>
using Predicate=std::function<bool(const std::pair<const unsigned int, Employee>&)>;
//names of products attached to a numeric serial number for each

using Container=std::unordered_map<unsigned int,Employee>;

//iterator : eidea of going one element to other without worrying about the actual process involved

//c++17
void DisplayMapUsingStructuredBinding(const Container& data){
    for( auto& [k,v] : data) { //syntactic sugar
        std::cout << "Key is : " << k << " and value is : " << v << "\n";
    }
}

void CreateEmployeeObjects(Container& data){
    //data.emplace(101,101,"Srija",20000.0f,22,11.1f);//you can delete id as the data member if id is also the key if you don't want to replicate
    //error
    data.emplace(
        std::piecewise_construct, //construct by considering by 2 pieces
        std::forward_as_tuple(101), //first piece is a tuple of 1 key
        std::forward_as_tuple(101,"Srija",20000.0f,22,11.1f) //second piece is a tuple of 5 items
    );

    data.emplace(
        std::piecewise_construct, //construct by considering by 2 pieces
        std::forward_as_tuple(102), //first piece is a tuple of 1 key
        std::forward_as_tuple(102,"Moksha",40000.0f,24,14.1f) //second piece is a tuple of 5 items
    );

    data.emplace(
        std::piecewise_construct, //construct by considering by 2 pieces
        std::forward_as_tuple(103), //first piece is a tuple of 1 key
        std::forward_as_tuple(103,"Megha",54000.0f,27,8.1f) //second piece is a tuple of 5 items
    );
}

void FindAverageSalary(const Container& data){
    /*
        For every pair of key and value,

        go to value section and us ethe getter to fetch salary.

        Add salary to total

        At the end of the loop, divide total by size of hash value
    */
   float total {0.0f};
   for(auto&& [k,v] : data){
    total+=v.salary();
   }
   std::cout << total / data.size() << "\n";
}

void FindEmployeeId(const Container& data, unsigned int key){
    auto itr=data.find(key);
    //std::unordered_map<unsigned int,Employee>::const_iterator itr=data.find(key);//datatype of pointer

    if(itr==data.end()){
        std::cerr << "Employee with given key : " << key << " is not found\n";
    }
    else {
        std::cout << itr->second << "\n";
    }
}

void FilterEmployeeByPredicate( const Container& data, Predicate fn){
    /*
        do not apply filter on key, condition is based on object's value
    */
    // Note : while extracting pairs from an unordered map, the key part shall always be constant!
    for(const std::pair<const unsigned int, Employee>& p : data){
        if(fn(p)){
            std::cout << p.second << "\n";
        }
    }
}

int main()
{
    Container data;

    CreateEmployeeObjects(data);
    DisplayMapUsingStructuredBinding(data);
    FilterEmployeeByPredicate(
        data, [](const std::pair<const unsigned int, Employee>& p){
            return p.second.age() > 25;
        }
    );

}