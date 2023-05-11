#include "Serialization.hpp"

std::vector<Project> serializationProject(const std::vector<std::vector<std::string>> &answer)
{
    std::vector<Project> result;
    for (const auto &data : answer)
    {
        Project project;
        project.Id = std::stoi(data[0]);
        project.Name = data[1];
        project.CreatorId = std::stoi(data[2]);
        result.push_back(project);
    }
    return result;
}

std::vector<Board> serializationBoard(const std::vector<std::vector<std::string>> &answer)
{
    return std::vector<Board>();
}

std::vector<User> serializationUser(const std::vector<std::vector<std::string>> &answer)
{
    return std::vector<User>();
}

std::vector<Task> serializationTask(const std::vector<std::vector<std::string>> &answer)
{
    return std::vector<Task>();
}
