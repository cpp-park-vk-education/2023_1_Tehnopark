#pragma once
#include <memory>
#include "DbDriverInterface.hpp"
#include "ProjectRepoInterface.hpp"
#include "Project.hpp"

using DbDriverSPtr = std::shared_ptr<DbDriverInterface>;

class ProjectRepo : public ProjectRepoInterface
{
public:
    ProjectRepo(DbDriverSPtr dr);
    std::vector<Project> GetUserProjects(int userId) override;
    Project GetProjectById(int projectId) override;
    bool CreateProject(int userId, const std::string &projectName) override;
    bool RemoveProjectById(int projectId) override;
    bool AddUserToProject(int userId, int projectId) override;
    bool SetDescription(int projectId, const std::string &description) override;

private:
    DbDriverSPtr dr_;
};
