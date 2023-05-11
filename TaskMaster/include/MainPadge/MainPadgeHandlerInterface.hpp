#pragma once
#include <vector>
#include <string>
#include "Project.hpp"

class MainPadgeHandlerInterface
{
public:
    virtual ~MainPadgeHandlerInterface() {}
    virtual std::vector<Project> GetUserProjects(int userId) = 0;
    virtual Project GetProjectById(int projectId) = 0;
    virtual bool CreateProject(int userId, const std::string &projectName) = 0;
};

