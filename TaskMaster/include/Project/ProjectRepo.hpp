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
    bool AddUserToProject(int projectId, const std::string &userName) override;
    bool UpdateProject(const Project& project) override;

private:
    DbDriverSPtr dr_;
};
