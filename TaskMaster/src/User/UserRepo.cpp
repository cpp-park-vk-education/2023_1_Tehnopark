#include "UserRepo.hpp"
#include "Serialization.hpp"
#include <iostream>

bool UserRepo::EditUser(size_t userId, const std::string &userName)
{
    _dr->Exec("UPDATE user SET name=\'" + userName + "\' WHERE id=" + std::to_string(userId) + ";");
    return true;
}
bool UserRepo::CreateUser(const std::string &userName)
{
    _dr->Exec("INSERT INTO user (name) VALUES (\'" + userName + "\');");
    return true;
}
bool UserRepo::AddTaskToUser(int userId, int taskId)
{
    _dr->Exec("INSERT INTO task_users (user_id, task_id) VALUES (\'" + std::to_string(userId) + "\', \'"
              + std::to_string(taskId) + "\');");
    return true;
}
bool UserRepo::DeleteTaskFromUser(int userId, int taskId)
{
    _dr->Exec("DELETE FROM task_users WHERE user_id=" + std::to_string(userId)
              + " AND task_id=" + std::to_string(taskId) + ";");
    return true;
}
bool UserRepo::AddProjectToUser(int userId, int projectId)
{
    _dr->Exec("INSERT INTO project_users (user_id, project_id) VALUES (\'" + std::to_string(userId) + "\', \'"
              + std::to_string(projectId) + "\');");
    return true;
}
bool UserRepo::DeleteProjectFromUser(int userId, int projectId)
{
    _dr->Exec("DELETE FROM project_users WHERE user_id=" + std::to_string(userId)
              + " AND project_id=" + std::to_string(projectId) + ";");
    return true;
}
std::vector<User> UserRepo::GetUsersForTask(int taskId)
{
    auto answer = _dr->Exec("SELECT * FROM user INNER JOIN task_users ON task_users.user_id=user.id WHERE task_users.task_id=" + std::to_string(taskId) + ";");
 //   if (answer.size() == 0)
  //      throw std::runtime_error("Users with task_Id=" + std::to_string(taskId) + " not found");
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
    auto answer = _dr->Exec("SELECT * FROM user INNER JOIN project_users ON project_users.user_id=user.id WHERE project_users.project_id=" + std::to_string(projectId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Users with project_Id=" + std::to_string(projectId) + " not found");
    std::vector<User> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationUser(data));
    }
    return res;
}
std::vector<User> UserRepo::GetUsersNotInProject(int projectId)
{
    // project_users.project_id<>" + std::to_string(projectId) + "
    auto answer = _dr->Exec("SELECT public.user.id, public.user.identity FROM public.user FULL OUTER JOIN project_users ON project_users.user_id=public.user.id WHERE project_users.project_id=" + std::to_string(projectId) + " AND project_users.user_id IS NULL;");
    if (answer.size() == 0)
        return std::vector<User>();
    std::vector<User> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationUser(data));
    }
    return res;
}
std::vector<User> UserRepo::GetUsers()
{
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

User UserRepo::GetUser(int userId)
{
    if (!_dr->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = _dr->Exec("SELECT user.id, user.name FROM user WHERE user.id=" + std::to_string(userId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Users with userId=" + std::to_string(userId) + " not found");
    return serializationUser(answer[0]);
}

User UserRepo::GetUserByIdentity(int userIdentityId)
{
    if (!_dr->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = _dr->Exec("SELECT user.id, user.name FROM user WHERE user.auth_identity_id=" + std::to_string(userIdentityId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Users with auth_identity_id=" + std::to_string(userIdentityId) + " not found");
    return serializationUser(answer[0]);
}

bool UserRepo::CreateUserWithIdentity(int userIdentityId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("INSERT INTO user (name, auth_identity_id) SELECT auth_identity.identity, auth_identity.id FROM auth_identity WHERE auth_identity.id =" + std::to_string(userIdentityId) + ";");
    return true;
}

