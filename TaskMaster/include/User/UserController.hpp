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
    User CreateUser(const std::string &userName) override;
    bool AddTaskToUser(int userId, int taskId) override;
    bool DeleteTaskFromUser(int userId, int taskId) override;
    bool AddProjectToUser(int userId, int projectId) override;
    bool DeleteProjectFromUser(int userId, int projectId) override;
    std::vector<User> GetUsersForTask(int taskId) override;
    std::vector<User> GetUsersForProject(int projectId) override;
    std::vector<User> GetUsers() override;
    User GetUser(int userId) override;
    User GetUserByIdentity(int userIdentityId) override;
<<<<<<< HEAD
    bool CreateUserWithIdentity(int userIdentityId) override;
    std::vector<User> GetUsersNotInProject(int projectId) override;
=======
    User CreateUserWithIdentity(int userIdentityId) override;
>>>>>>> 14e35495c0901db205c4043110e84b0afac9a199
    ~UserController(){}
private:
    UserRepoUPtr _repo;
};