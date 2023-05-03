#pragma once
#include "Project.hpp"

class ProjectRepoInterface
{
public:
    virtual ~ProjectRepoInterface() {}
    virtual Project GetProjectById(int projectId) = 0;
    virtual bool CreateProject(int userId, const std::string &projectName) = 0;
    virtual bool RemoveProjectById(int projectId) = 0;
    virtual bool AddUserToProject(int projectId, const std::string &userName) = 0;
    virtual bool UpdateProject(const Project& project) = 0;
};
