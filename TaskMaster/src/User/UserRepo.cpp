#include "UserRepo.hpp"
#include "Serialization.hpp"
#include <iostream>

bool UserRepo::EditUser(size_t userId, const std::string &userName)
{
    _dr->Exec("UPDATE db_user SET name=\'" + userName + "\' WHERE id=" + std::to_string(userId) + ";");
    return true;
}
bool UserRepo::CreateUser(const std::string &userName)
{
    _dr->Exec("INSERT INTO db_user (name) VALUES (\'" + userName + "\');");
    return true;
}
bool UserRepo::AddTaskToUser(int userId, int taskId)
{
    _dr->Exec("INSERT INTO db_task_users (user_id, task_id) VALUES (\'" + std::to_string(userId) + "\', \'"
              + std::to_string(taskId) + "\');");
    return true;
}
bool UserRepo::DeleteTaskFromUser(int userId, int taskId)
{
    _dr->Exec("DELETE FROM db_task_users WHERE user_id=" + std::to_string(userId)
              + " AND task_id=" + std::to_string(taskId) + ";");
    return true;
}
bool UserRepo::AddProjectToUser(int userId, int projectId)
{
    _dr->Exec("INSERT INTO db_project_users (user_id, project_id) VALUES (\'" + std::to_string(userId) + "\', \'"
              + std::to_string(projectId) + "\');");
    return true;
}
bool UserRepo::DeleteProjectFromUser(int userId, int projectId)
{
    _dr->Exec("DELETE FROM db_project_users WHERE user_id=" + std::to_string(userId)
              + " AND project_id=" + std::to_string(projectId) + ";");
    return true;
}
std::vector<User> UserRepo::GetUsersForTask(int taskId)
{
    auto answer = _dr->Exec("SELECT * FROM db_user INNER JOIN db_task_users ON db_task_users.user_id=db_user.id WHERE db_task_users.task_id=" + std::to_string(taskId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Users with task_Id=" + std::to_string(taskId) + " not found");
    std::cout << answer[0][0];
    std::vector<User> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationUser(data));
    }
    return res;
}
std::vector<User> UserRepo::GetUsersForProject(int projectId)
{
    auto answer = _dr->Exec("SELECT * FROM db_user INNER JOIN db_project_users ON db_project_users.user_id=db_user.id WHERE db_project_users.project_id=" + std::to_string(projectId) + ";");
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
    auto answer = _dr->Exec("SELECT * FROM db_user;");
    if (answer.size() == 0)
        throw std::runtime_error("Database has no users");
    std::vector<User> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationUser(data));
    }
    return res;
}