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
    virtual bool EditUser(size_t userId, const std::string &userName) = 0;
    virtual bool CreateUser(const std::string &userName) = 0;
    virtual bool AddTaskToUser(int userId, int taskId) = 0;
    virtual bool DeleteTaskFromUser(int userId, int taskId) = 0;
    virtual bool AddProjectToUser(int userId, int projectId) = 0;
    virtual bool DeleteProjectFromUser(int userId, int projectId) = 0;
    virtual std::vector<User> GetUsersForTask(int taskId) = 0;
    virtual std::vector<User> GetUsersForProject(int projectId) = 0;
    virtual User GetUser(int userId) = 0;
    virtual User GetUserByInentity(int userIdentityId) = 0;
    virtual bool CreateUserWithInentity(int userIdentityId) = 0;
    virtual std::vector<User> GetUsers() = 0;
};