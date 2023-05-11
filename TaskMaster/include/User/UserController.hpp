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
    UserController(UserRepoUPtr repo): repo_(std::move(repo)) {}
    bool EditUser(const User& user) override;
    bool AddTaskToUser(const User& user, const Task& task) override;
    bool DeleteTaskFromUser(const User& user, const Task& task) override;
    bool AddBoardToUser(const User& user, const Board& board) override;
    bool DeleteBoardFromUser(const User& user, const Board& board) override;
    bool AddProjectToUser(const User& user, const Project& project) override;
    bool DeleteProjectFromUser(const User& user, const Project& project) override;
    std::vector<User> GetUsersForBoard(const Board& board) override;
    std::vector<User> GetUsersForTask(const Task& task) override;
    std::vector<User> GetUsersForProject(const Project& project) override;
    std::vector<User> GetUsers() override;
    ~UserController(){}
private:
    UserRepoUPtr repo_;
};