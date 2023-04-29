#pragma once
#include "../../models/Project.hpp"
#include "../../models/Board.hpp"

class ProjectRepoInterface
{
public:
    virtual ~ProjectRepoInterface() {}
    virtual Project GetProjectById(int projectId) = 0;
    virtual void CreateProject(int userId) = 0;
    virtual void RemoveProjectById(int projectId) = 0;
    virtual void UpdateProject(const Project& project) = 0;
};
