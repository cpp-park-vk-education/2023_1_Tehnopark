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
    Board board;
    board.Id = std::stoi(answer[0]);
    board.ProjectId = std::stoi(answer[1]);
    board.CreatorId = std::stoi(answer[2]);
    board.Name = answer[3];
    board.Text = answer[4];
    return board;
}

User serializationUser(const std::vector<std::string> &answer)
{
    User user;
    user.Id = std::stoi(answer[0]);
    user.FirstName = answer[1];
    user.LastName = answer[2];
    user.UserName = answer[3];
    user.CompanyId = std::stoi(answer[4]);
    user.Post = answer[5];
    return user;
}

Task serializationTask(const std::vector<std::string> &answer)
{
    return Task();
}
