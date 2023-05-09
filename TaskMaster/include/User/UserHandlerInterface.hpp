#pragma once
#include <string>
#include <vector>
#include <memory>
#include "User.hpp"
#include "Task.hpp"
#include "Board.hpp"
#include "Project.hpp"

class UserHandlerInterface
{
public:
    virtual bool EditUser(const User& user) = 0;
    virtual bool AddTaskToUser(const User& user, const Task& task) = 0;
    virtual bool DeleteTaskFromUser(const User& user, const Task& task) = 0;
    virtual bool AddBoardToUser(const User& user, const Board& board) = 0;
    virtual bool DeleteBoardFromUser(const User& user, const Board& board) = 0;
    virtual bool AddProjectToUser(const User& user, const Project& project) = 0;
    virtual bool DeleteProjectFromUser(const User& user, const Project& project) = 0;
    virtual std::vector<User> GetUsersForBoard(const Board& board) = 0;
    virtual std::vector<User> GetUsersForTask(const Task& task) = 0;
    virtual std::vector<User> GetUsersForProject(const Project& project) = 0;
    virtual std::vector<User> GetUsers() = 0;
};