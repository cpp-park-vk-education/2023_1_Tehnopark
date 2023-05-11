#pragma once
#include <string>
#include <vector>
#include "User.hpp"
#include "Task.hpp"
#include "Board.hpp"
#include "Project.hpp"

class UserRepoInterface
{
public:
    virtual ~UserRepoInterface() {}
    virtual void EditUser(const User& user) = 0;
    virtual void AddTaskToUser(const User& user, const Task& task) = 0;
    virtual void DeleteTaskFromUser(const User& user, const Task& task) = 0;
    virtual void AddBoardToUser(const User& user, const Board& board) = 0;
    virtual void DeleteBoardFromUser(const User& user, const Board& board) = 0;
    virtual void AddProjectToUser(const User& user, const Project& project) = 0;
    virtual void DeleteProjectFromUser(const User& user, const Project& project) = 0;
    virtual std::vector<User> GetUsersForBoard(const Board& board) = 0;
    virtual std::vector<User> GetUsersForTask(const Task& task) = 0;
    virtual std::vector<User> GetUsersForProject(const Project& project) = 0;
    virtual std::vector<User> GetUsers() = 0;
};