#pragma once
#include <string>
#include <vector>
#include <memory>
#include "UserRepoInterface.hpp"
#include "DbDriverInterface.hpp"
#include "User.hpp"
#include "Task.hpp"
#include "Board.hpp"

using DbDriverSPtr = std::shared_ptr<DbDriverInterface>;

class UserRepo : public UserRepoInterface
{
public:
    UserRepo(DbDriverSPtr dr): _dr(dr) {}
    bool EditUser(size_t userId, const std::string &userName) override;
    bool CreateUser(const std::string &userName) override;
    bool AddTaskToUser(int userId, int taskId) override;
    bool DeleteTaskFromUser(int userId, int taskId) override;
    bool AddProjectToUser(int userId, int projectId) override;
    bool DeleteProjectFromUser(int userId, int projectId) override;
    std::vector<User> GetUsersForTask(int taskId) override;
    std::vector<User> GetUsersForProject(int projectId) override;
    std::vector<User> GetUsers() override;
    ~UserRepo() {}
private:
    DbDriverSPtr _dr;
};
