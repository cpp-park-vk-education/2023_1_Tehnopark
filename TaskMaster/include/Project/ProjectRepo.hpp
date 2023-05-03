#pragma once
#include "ProjectRepoInterface.hpp"
#include "Project.hpp"
#include "Board.hpp"

class ProjectRepo : ProjectRepoInterface
{
public:
    ProjectRepo();
    virtual ~ProjectRepo();
    virtual Project GetProjectById(int projectId);
    virtual void CreateProject(int userId);
    virtual void RemoveProjectById(int projectId);
    virtual void UpdateProject(const Project& project);
};
