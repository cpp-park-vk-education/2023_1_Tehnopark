#pragma once
#include <string>
#include <vector>
#include <memory>
#include "User.hpp"
#include "Task.hpp"
#include "Board.hpp"
#include "Project.hpp"
#include "UserHandlerInterface.hpp"
#include "UserRepoInterface.hpp"

using UserRepoUPtr = std::unique_ptr<UserRepoInterface>;

class UserController : public UserHandlerInterface
{
public:
    UserController(UserRepoUPtr repo): _repo(std::move(repo)) {}
    bool EditUser(size_t userId, const std::string &userName) override;
    bool CreateUser(const std::string &userName) override;
    bool AddTaskToUser(int userId, int taskId) override;
    bool DeleteTaskFromUser(int userId, int taskId) override;
    bool AddProjectToUser(int userId, int projectId) override;
    bool DeleteProjectFromUser(int userId, int projectId) override;
    std::vector<User> GetUsersForTask(int taskId) override;
    std::vector<User> GetUsersForProject(int projectId) override;
    std::vector<User> GetUsers() override;
    User GetUser(int userId) override;
    User GetUserByIdentity(int userIdentityId) override;
    bool CreateUserWithIdentity(int userIdentityId) override;
    ~UserController(){}
private:
    UserRepoUPtr _repo;
};