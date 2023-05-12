#pragma once
#include <vector>
#include "Project.hpp"

class ProjectRepoInterface
{
public:
    virtual ~ProjectRepoInterface() {}
    virtual std::vector<Project> GetUserProjects(size_t userId) = 0;
    virtual Project GetProjectById(size_t projectId) = 0;
    virtual bool CreateProject(size_t userId, const std::string &projectName) = 0;
    virtual bool RemoveProjectById(size_t projectId) = 0;
    virtual bool AddUserToProject(size_t projectId, const std::string &userName) = 0;
    virtual bool UpdateProject(const Project& project) = 0;
};
