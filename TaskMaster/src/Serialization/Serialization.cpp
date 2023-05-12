#include "Serialization.hpp"

Project serializationProject(const std::vector<std::string> &answer)
{
    Project project;
    project.Id = std::stoi(answer[0]);
    project.Name = answer[1];
    project.CreatorId = std::stoi(answer[2]);

    return project;
}

Board serializationBoard(const std::vector<std::string> &answer)
{
    return Board();
}

User serializationUser(const std::vector<std::string> &answer)
{
    return User();
}

Task serializationTask(const std::vector<std::string> &answer)
{
    return Task();
}
