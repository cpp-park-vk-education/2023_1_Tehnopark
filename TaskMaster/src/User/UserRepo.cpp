#include "UserRepo.hpp"
#include "Serialization.hpp"
#include <iostream>

bool UserRepo::EditUser(size_t userId, const std::string &userName)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("UPDATE db_user SET user=" + userName + "WHERE id=" + std::to_string(userId) + ";");
    return true;
}
bool UserRepo::CreateUser(const std::string &userName)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("INSERT INTO db_user (name) VALUES (" + userName + ";");
    return true;
}
bool UserRepo::AddTaskToUser(int userId, int taskId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("INSERT INTO db_task_users (user_id, task_id) VALUES (" + std::to_string(userId) + ", "
              + std::to_string(taskId) + ");");
    return true;
}
bool UserRepo::DeleteTaskFromUser(int userId, int taskId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("DELETE FROM db_task_users WHERE user_id=" + std::to_string(userId)
              + "AND task_id=" + std::to_string(taskId) + ";");
    return true;
}
bool UserRepo::AddProjectToUser(int userId, int projectId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("INSERT INTO db_project_users (user_id, project_id) VALUES (" + std::to_string(userId) + ", "
              + std::to_string(projectId) + ");");
    return true;
}
bool UserRepo::DeleteProjectFromUser(int userId, int projectId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("DELETE FROM db_project_users WHERE user_id=" + std::to_string(userId)
              + "AND project_id=" + std::to_string(projectId) + ";");
    return true;
}
std::vector<User> UserRepo::GetUsersForTask(int taskId)
{
    if (!_dr->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = _dr->Exec("SELECT user.id, user.name FROM db_task_users INNER JOIN user ON db_task_users.user_id=user.id WHERE db_task_users.task_id=" + std::to_string(taskId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Users with task_Id=" + std::to_string(taskId) + " not found");
    std::vector<User> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationUser(data));
    }
    return res;
}
std::vector<User> UserRepo::GetUsersForProject(int projectId)
{
    if (!_dr->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = _dr->Exec("SELECT user.id, user.name FROM db_project_users INNER JOIN user ON db_project_users.user_id=user.id WHERE db_project_users.project_id=" + std::to_string(projectId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Users with project_Id=" + std::to_string(projectId) + " not found");
    std::vector<User> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationUser(data));
    }
    return res;
}
std::vector<User> UserRepo::GetUsers()
{
    if (!_dr->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = _dr->Exec("SELECT * FROM user;");
    if (answer.size() == 0)
        throw std::runtime_error("Database has no users");
    std::vector<User> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationUser(data));
    }
    return res;
}