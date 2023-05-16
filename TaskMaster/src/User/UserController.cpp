#include "UserController.hpp"

bool UserController::EditUser(size_t userId, const std::string &userName)
{
    return _repo->EditUser(userId, userName);
}
bool UserController::CreateUser(const std::string &userName)
{
    return _repo->CreateUser(userName);
}
bool UserController::AddTaskToUser(int userId, int taskId)
{
    return _repo->AddTaskToUser(userId, taskId);
}
bool UserController::DeleteTaskFromUser(int userId, int taskId)
{
    return _repo->DeleteTaskFromUser(userId, taskId);
}
bool UserController::AddProjectToUser(int userId, int projectId)
{
    return _repo->AddProjectToUser(userId, projectId);
}
bool UserController::DeleteProjectFromUser(int userId, int projectId)
{
    return _repo->DeleteProjectFromUser(userId, projectId);
}
std::vector<User> UserController::GetUsersForTask(int taskId)
{
    return _repo->GetUsersForTask(taskId);
}
std::vector<User> UserController::GetUsersForProject(int projectId)
{
    return _repo->GetUsersForProject(projectId);
}
std::vector<User> UserController::GetUsers()
{
    return _repo->GetUsers();
}

User UserController::GetUser(int userId)
{
    return _repo->GetUser(userId);
}

User UserController::GetUserByIdentity(int userIdentityId)
{
    return _repo->GetUserByIdentity(userIdentityId);
}

bool UserController::CreateUserWithIdentity(int userIdentityId)
{
    return _repo->CreateUserWithIdentity(userIdentityId);
}
