#include <iostream>
#include <exception>
#include "string"
#include "ProjectRepo.hpp"
#include "DbDriver.hpp"
#include "Serialization.hpp"

ProjectRepo::ProjectRepo(DbDriverSPtr dr) : dr_(dr) {}

std::vector<Project> ProjectRepo::GetUserProjects(size_t userId)
{
    auto answer = dr_->Exec("SELECT * FROM db_project WHERE creator_id=" + std::to_string(userId));
    std::vector<Project> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationProject(data));
    }
    return res;
}

Project ProjectRepo::GetProjectById(size_t projectId)
{
    auto answer = dr_->Exec("SELECT * FROM db_project WHERE id=" + std::to_string(projectId));
    if (answer.size() == 0)
    {
        throw std::runtime_error("Project with ID " + std::to_string(projectId) + " not found");
    }
    return serializationProject(answer[0]);
}

bool ProjectRepo::CreateProject(size_t creatorId, const std::string &projectName)
{
    dr_->Exec("INSERT INTO db_project (name, creator_Id) VALUES (\'" + projectName + "\'," + std::to_string(creatorId) + ")");
    return true;
}

bool ProjectRepo::RemoveProjectById(size_t projectId)
{
    dr_->Exec("DELETE FROM db_project WHERE id = " + std::to_string(projectId));
    return true;
}

bool ProjectRepo::AddUserToProject(size_t projectId, const std::string &userName)
{
    return true;
}

bool ProjectRepo::UpdateProject(const Project &project)
{
    return true;
}
