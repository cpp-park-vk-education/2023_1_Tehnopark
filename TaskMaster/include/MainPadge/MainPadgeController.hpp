#pragma once
#include <vector>
#include <string>
#include <memory>
#include "ProjectRepoInterface.hpp"
#include "MainPadgeHandlerInterface.hpp"
#include "Project.hpp"

using IProjectRepoUptr = std::unique_ptr<ProjectRepoInterface>;

class MainPadgeController : public MainPadgeHandlerInterface
{
public:
    MainPadgeController(IProjectRepoUptr projectRepo);
    std::vector<Project> GetUserProjects(int userId) override;
    virtual Project GetProjectById(int projectId) override;
    virtual bool CreateProject(int userId, const std::string &projectName) override;

private:
    IProjectRepoUptr projectRepo_;
};