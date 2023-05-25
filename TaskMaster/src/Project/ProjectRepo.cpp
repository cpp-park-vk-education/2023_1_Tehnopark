#include <iostream>
#include <exception>
#include "string"
#include "ProjectRepo.hpp"
#include "DbDriver.hpp"
#include "Serialization.hpp"

ProjectRepo::ProjectRepo(DbDriverSPtr dr) : dr_(dr) {}

std::vector<Project> ProjectRepo::GetUserProjects(int userId)
{
    auto answer = dr_->Exec("SELECT * FROM project INNER JOIN project_users ON project_users.project_id=project.id WHERE project_users.user_id=" + std::to_string(userId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Projects with user_Id=" + std::to_string(userId) + " not found");
    std::vector<Project> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationProject(data));
    }
    return res;
}

Project ProjectRepo::GetProjectById(int projectId)
{
    auto answer = dr_->Exec("SELECT * FROM project WHERE id=" + std::to_string(projectId));
    if (answer.size() == 0)
    {
        throw std::runtime_error("Project with ID " + std::to_string(projectId) + " not found");
    }
    return serializationProject(answer[0]);
}

bool ProjectRepo::CreateProject(int creatorId, const std::string &projectName)
{
    dr_->Exec("INSERT INTO project (name, creator_Id) VALUES (\'" + projectName + "\'," + std::to_string(creatorId) + ")");
    return true;
}

bool ProjectRepo::RemoveProjectById(int projectId)
{
    dr_->Exec("DELETE FROM project WHERE id = " + std::to_string(projectId));
    return true;
}

bool ProjectRepo::AddUserToProject(int projectId, const std::string &userName)
{
    // dr_->Exec("INSERT INTO project (name, creator_Id) VALUES (\'" + projectName + "\'," + std::to_string(creatorId) + ")");
    return true;
}

bool ProjectRepo::UpdateProject(const Project &project)
{
    return true;
}
