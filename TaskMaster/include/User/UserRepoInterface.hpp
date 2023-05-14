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
    virtual bool EditUser(size_t userId, const std::string &firstName, const std::string &lastName, 
         const std::string &userName, size_t companyId, const std::string &post) = 0;
    virtual bool AddTaskToUser(int userId, int taskId) = 0;
    virtual bool DeleteTaskFromUser(int userId, int taskId) = 0;
    virtual bool AddBoardToUser(int userId, int boardId) = 0;
    virtual bool DeleteBoardFromUser(int userId, int boardId) = 0;
    virtual bool AddProjectToUser(int userId, int projectId) = 0;
    virtual bool DeleteProjectFromUser(int userId, int projectId) = 0;
    virtual std::vector<User> GetUsersForBoard(int boardId) = 0;
    virtual std::vector<User> GetUsersForTask(int taskId) = 0;
    virtual std::vector<User> GetUsersForProject(int projectId) = 0;
    virtual std::vector<User> GetUsers() = 0;
};