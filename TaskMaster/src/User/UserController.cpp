#include "UserController.hpp"

bool UserController::EditUser(size_t userId, const std::string &firstName, const std::string &lastName, 
        const std::string &userName, size_t companyId, const std::string &post)
{
    return _repo->EditUser(userId, firstName, lastName, userName, companyId, post);
}
bool UserController::AddTaskToUser(int userId, int taskId)
{
    return _repo->AddTaskToUser(userId, taskId);
}
bool UserController::DeleteTaskFromUser(int userId, int taskId)
{
    return _repo->DeleteTaskFromUser(userId, taskId);
}
bool UserController::AddBoardToUser(int userId, int boardId)
{
    return _repo->AddBoardToUser(userId, boardId);
}
bool UserController::DeleteBoardFromUser(int userId, int boardId)
{
    return _repo->DeleteBoardFromUser(userId, boardId);
}
bool UserController::AddProjectToUser(int userId, int projectId)
{
    return _repo->AddProjectToUser(userId, projectId);
}
bool UserController::DeleteProjectFromUser(int userId, int projectId)
{
    return _repo->DeleteProjectFromUser(userId, projectId);
}
std::vector<User> UserController::GetUsersForBoard(int boardId)
{
    return _repo->GetUsersForBoard(boardId);
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