#include <iostream>
#include <exception>
#include "string"
#include "ProjectRepo.hpp"
#include "DbDriver.hpp"
#include "Serialization.hpp"

ProjectRepo::ProjectRepo(DbDriverSPtr dr) : dr_(dr) {}

std::vector<Project> ProjectRepo::GetUserProjects(int userId)
{
    if (!dr_->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = dr_->Exec("SELECT * FROM project WHERE creator_id=" + std::to_string(userId));
    std::vector<Project> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationProject(data));
    }
    return res;
}

Project ProjectRepo::GetProjectById(int projectId)
{
    if (!dr_->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = dr_->Exec("SELECT * FROM project WHERE id=" + std::to_string(projectId));
    if (answer.size() == 0)
    {
        throw std::runtime_error("Project with ID " + std::to_string(projectId) + " not found");
    }
    return serializationProject(answer[0]);
}

bool ProjectRepo::CreateProject(int creatorId, const std::string &projectName)
{
    if (!dr_->Connected())
        throw std::runtime_error("Database is unavailable");
    dr_->Exec("INSERT INTO project (name, creator_Id) VALUES (\'" + projectName + "\'," + std::to_string(creatorId) + ")");
    return true;
}

bool ProjectRepo::RemoveProjectById(int projectId)
{
    if (!dr_->Connected())
        throw std::runtime_error("Database is unavailable");
    dr_->Exec("DELETE FROM project WHERE id = " + std::to_string(projectId));
    return true;
}

bool ProjectRepo::AddUserToProject(int userId, int projectId)
{
    if (!dr_->Connected())
        throw std::runtime_error("Database is unavailable");
    dr_->Exec("INSERT INTO project_users (project_id, user_id) VALUES (" + std::to_string(projectId) + "," + std::to_string(userId) + ")");
    return true;
}

bool ProjectRepo::SetDescription(int projectId, const std::string &description)
{
    if (!dr_->Connected())
        throw std::runtime_error("Database is unavailable");
    dr_->Exec("UPDATE project SET description = " + description + " WHERE projectId = " + std::to_string(projectId) + ")");
    return true;
}
