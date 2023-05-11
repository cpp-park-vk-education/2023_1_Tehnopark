#include <iostream>
#include "string"
#include "ProjectRepo.hpp"
#include "DbDriver.hpp"
#include "Serialization.hpp"

ProjectRepo::ProjectRepo(){}
ProjectRepo::ProjectRepo(DbDriverSPtr dr) : dr_(dr) {}

std::vector<Project> ProjectRepo::GetUserProjects(int userId)
{
    auto answer = dr_->Exec("SELECT * FROM db_project WHERE creator_id=" + std::to_string(userId));
    std::vector<Project> res = serializationProject(answer);
    return res;
}

Project ProjectRepo::GetProjectById(int projectId)
{
    auto result = dr_->Exec("");
    return Project(1, "");
}

bool ProjectRepo::CreateProject(int creatorId, const std::string &projectName)
{
    return true;
}

bool ProjectRepo::RemoveProjectById(int projectId)
{
    return true;
}

bool ProjectRepo::AddUserToProject(int projectId, const std::string &userName)
{
    return true;
}

bool ProjectRepo::UpdateProject(const Project &project)
{
    return true;
}
