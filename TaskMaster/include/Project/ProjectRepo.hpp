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
    std::vector<Project> GetUserProjects(size_t userId) override;
    Project GetProjectById(size_t projectId) override;
    bool CreateProject(size_t userId, const std::string &projectName) override;
    bool RemoveProjectById(size_t projectId) override;
    bool AddUserToProject(size_t projectId, const std::string &userName) override;
    bool UpdateProject(const Project& project) override;

private:
    DbDriverSPtr dr_;
};
