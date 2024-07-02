#include "Project.h"

Project::Project(std::string id, unsigned int size, float budget)
{
    this->_id = id;
    this->_budget = budget;
    this->_teamSize = size;
}

Project::~Project()
{
    std::cout << "Project with ID: " << _id << " deleted\n";
}
