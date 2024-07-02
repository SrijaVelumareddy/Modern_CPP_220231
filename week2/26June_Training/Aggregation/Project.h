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

    float budget() const { return _budget; }

    std::string id() const { return _id; }

    unsigned int teamSize() const { return _teamSize; }

    // float budget() const { return _budget; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs) {
        os << "_id: " << rhs._id
           << " _teamSize: " << rhs._teamSize
           << " _budget: " << rhs._budget;
        return os;
    }
};

#endif // PROJECT_H
