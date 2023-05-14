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
    bool EditUser(size_t userId, const std::string &firstName, const std::string &lastName, 
         const std::string &userName, size_t companyId, const std::string &post) override;
    bool AddTaskToUser(int userId, int taskId) override;
    bool DeleteTaskFromUser(int userId, int taskId) override;
    bool AddBoardToUser(int userId, int boardId) override;
    bool DeleteBoardFromUser(int userId, int boardId) override;
    bool AddProjectToUser(int userId, int projectId) override;
    bool DeleteProjectFromUser(int userId, int projectId) override;
    std::vector<User> GetUsersForBoard(int boardId) override;
    std::vector<User> GetUsersForTask(int taskId) override;
    std::vector<User> GetUsersForProject(int projectId) override;
    std::vector<User> GetUsers() override;
    ~UserController(){}
private:
    UserRepoUPtr _repo;
};