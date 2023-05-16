#include "Serialization.hpp"
#include <iostream>

Project serializationProject(const std::vector<std::string> &answer)
{
    Project project;
    project.Id = std::stoi(answer[0]);
    project.Name = answer[1];
    project.CreatorId = std::stoi(answer[2]);
    project.Description = answer[4];

    return project;
}
