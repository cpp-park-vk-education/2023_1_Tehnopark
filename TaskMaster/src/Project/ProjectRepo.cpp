#include "ProjectRepo.hpp"

ProjectRepo::ProjectRepo(DbDriverSPtr dr) : dr_(dr) { }

Project ProjectRepo::GetProjectById(int projectId)
{
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
