#pragma once
#include <string>
#include <vector>
#include "UserRepoInterface.hpp"
#include "DbDriverInterface.hpp"
#include "User.hpp"
#include "Task.hpp"
#include "Board.hpp"


class UserRepo : public UserRepoInterface
{
public:
    UserRepo(DbDriverInterface* dr): dr_(dr) {}
    bool EditUser(const User& user) override;
    bool AddTaskToUser(const User& user, const Task& task) override;
    bool AddBoardToUser(const User& user, const Board& board) override;
    std::vector<User> GetUsersForBoard(int boardId) override;
    std::vector<User> GetUsersForTask(int userId) override;
    std::vector<User> GetUsersForProject(int projectId) override;
    std::vector<User> GetUsers() override;
    ~UserRepo() {}
private:
    DbDriverInterface* dr_;
};