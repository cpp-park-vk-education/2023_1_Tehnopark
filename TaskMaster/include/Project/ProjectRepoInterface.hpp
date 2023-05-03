#pragma once
#include "Project.hpp"
#include "Board.hpp"

class ProjectRepoInterface
{
public:
    virtual ~ProjectRepoInterface() {}
    virtual Project GetProjectById(int projectId) = 0;
    virtual void CreateProject(int userId, const std::string &projectName) = 0;
    virtual void RemoveProjectById(int projectId) = 0;
    virtual void AddUserToProject(int projectId, const std::string &userName) = 0;
    virtual void UpdateProject(const Project& project) = 0;
};
