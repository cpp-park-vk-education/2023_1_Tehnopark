#include "UserRepo.hpp"
#include "Serialization.hpp"
#include <iostream>

bool UserRepo::EditUser(size_t userId, const std::string &firstName, const std::string &lastName, 
        const std::string &userName, size_t companyId, const std::string &post)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("UPDATE users SET first_name=" + firstName + ", last_name=" + lastName +
              ", user_name=" + userName + ", company_id=" + std::to_string(companyId) + ", post=" + post +
              "WHERE id=" + std::to_string(userId) + ";");
    return true;
}
bool UserRepo::AddTaskToUser(int userId, int taskId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("INSERT INTO users_tasks (user_Id, task_Id) VALUES (" + std::to_string(userId) + ", "
              + std::to_string(taskId) + ");");
    return true;
}
bool UserRepo::DeleteTaskFromUser(int userId, int taskId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("DELETE FROM users_tasks WHERE user_Id=" + std::to_string(userId)
              + "AND task_Id=" + std::to_string(taskId) + ";");
    return true;
}
bool UserRepo::AddBoardToUser(int userId, int boardId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("INSERT INTO users_boards (user_Id, board_Id) VALUES (" + std::to_string(userId) + ", "
              + std::to_string(boardId) + ");");
    return true;
}
bool UserRepo::DeleteBoardFromUser(int userId, int boardId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("DELETE FROM users_boards WHERE user_Id=" + std::to_string(userId)
              + "AND board_Id=" + std::to_string(boardId) + ";");
    return true;
}
bool UserRepo::AddProjectToUser(int userId, int projectId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("INSERT INTO users_projects (user_Id, project_Id) VALUES (" + std::to_string(userId) + ", "
              + std::to_string(projectId) + ");");
    return true;
}
bool UserRepo::DeleteProjectFromUser(int userId, int projectId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("DELETE FROM users_projects WHERE user_Id=" + std::to_string(userId)
              + "AND project_Id=" + std::to_string(projectId) + ";");
    return true;
}
std::vector<User> UserRepo::GetUsersForBoard(int boardId)
{
    if (!_dr->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = _dr->Exec("SELECT users.id, users.first_name, users.last_name, users.user_name, users.company_Id, users.post FROM users_boards INNER JOIN users ON users_boards.user_Id=users.id WHERE users_boards.board_Id=" + std::to_string(boardId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Users with board_Id=" + std::to_string(boardId) + " not found");
    std::vector<User> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationUser(data));
    }
    return res;
}
std::vector<User> UserRepo::GetUsersForTask(int taskId)
{
    if (!_dr->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = _dr->Exec("SELECT users.id, users.first_name, users.last_name, users.user_name, users.company_Id, users.post FROM users_tasks INNER JOIN users ON users_tasks.user_Id=users.id WHERE users_tasks.task_Id=" + std::to_string(taskId) + ";");
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
    auto answer = _dr->Exec("SELECT users.id, users.first_name, users.last_name, users.user_name, users.company_Id, users.post FROM users_projects INNER JOIN users ON users_projects.user_Id=users.id WHERE users_projects.project_Id=" + std::to_string(projectId) + ";");
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
    auto answer = _dr->Exec("SELECT * FROM users;");
    if (answer.size() == 0)
        throw std::runtime_error("Database has no users");
    std::vector<User> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationUser(data));
    }
    return res;
}