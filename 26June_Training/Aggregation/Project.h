#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>

class Project
{
private:
    std::string _id;
    unsigned int _teamSize;
    float _budget;
public:
    Project(std::string id,  unsigned int size, float budget); 
    ~Project();
};

#endif // PROJECT_H
