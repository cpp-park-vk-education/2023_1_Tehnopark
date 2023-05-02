#pragma once
#include <string>
#include <vector>
#include "User.hpp"
#include "Task.hpp"
#include "Board.hpp"

class UserRepoInterface
{
public:
    virtual ~UserRepoInterface() {}
    virtual bool EditUser(const User& user) = 0;
    virtual bool AddTaskToUser(const User& user, const Task& task) = 0;
    virtual bool AddBoardToUser(const User& user, const Board& board) = 0;
    virtual std::vector<User> GetUsersForBoard(int boardId) = 0;
    virtual std::vector<User> GetUsersForTask(int userId) = 0;
    virtual std::vector<User> GetUsersForProject(int projectId) = 0;
    virtual std::vector<User> GetUsers() = 0;
};