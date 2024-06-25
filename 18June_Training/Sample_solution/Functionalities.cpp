#include "Functionalities.h"

void CreateObjects(Engine **engines, unsigned int size)
{
    engines[0] = new Engine(101,234,56.3f);
    engines[1] = new Engine(102,456,65.3f);
    engines[2] = new Engine(103,678,47.3f);
    engines[3] = new Engine(104,536,68.3f);
}

int AverageHorsePower(Engine **engines, unsigned int size)
{
    if(size==0) {
        throw std::invalid_argument("Size cannot be negative\n");
        // return;
    }
    int total=0;
    int count=0;
    for(int i=0;i<size;i++){
        total=total+engines[i]->horsepower();
        count++;
    }
    int avg=total/count;
    return avg;
}

float FindTorqueById(Engine **engines, unsigned int size, unsigned int id)
{
    if(size==0) {
        throw std::invalid_argument("Size cannot be negative\n");
        // return;
    }
    bool flag=false;
    for(int i=0;i<size;i++){
        if(engines[i]->id()==id){
            flag=true;
            // std::cout << engines[i]->torque() << "\n";
            return engines[i]->torque() ;
        }
    }
    if(!flag){
        throw IdNotFoundException("Id not found\n");
    }
    return 0.0f;
}

float FindHorsePowerForMinTorqueEngine(Engine **engines, unsigned int size)
{
     if(size==0) {
        throw std::invalid_argument("Size cannot be negative\n");
        // return;
    }
    bool flag=false;
    int index=0;
    int Min=engines[0]->torque();
    for(int i=0;i<size;i++){
        if(engines[i]){
            flag=true;
            if(Min<engines[i]->torque()){
                Min=engines[i]->torque();
                index=i;
            }
        }
    }
    if(flag==true){
        // std::cout << "The lowest horse power is: " << engines[index]->horsepower() << "\n";
        return engines[index]->horsepower();
    }
    if(flag==false){
        throw NullArrayException("Not found\n");
    }
    return 0.0f;
    
}

/*
    Think about inputs to a function

    Think aboutk 1 sure-shot way of completing the function and getting a valid output

    Now, start thinking of all possible ways, functions may not be completed based on inputs provided and system situations

*/