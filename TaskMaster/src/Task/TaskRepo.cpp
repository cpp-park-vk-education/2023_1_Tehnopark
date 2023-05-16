#include "TaskRepo.hpp"
#include "Serialization.hpp"
#include <iostream>

bool TaskRepo::EditTask(const Task& newTask)
{
    if (_dr->Connected())
        return false;
    _dr->Exec("UPDATE task SET name=\'" + newTask.Name 
                + "\', text=\'" + newTask.Text  
                + "\', status=" + std::to_string(static_cast<int>(newTask.Status)) 
                + ", board_id=" + std::to_string(newTask.BoardId)
                + " WHERE id=" + std::to_string(newTask.Id)+";");
    return true;
}
    
bool TaskRepo::CreateTask(const Task& Task)
{
    if (_dr->Connected())
        return false;
    _dr->Exec("INSERT INTO task (board_id, name, text) VALUES (" + std::to_string(Task.BoardId) + ",\'" + Task.Name + "\'," + "\'" + Task.Text + "\');");
    return true;
}
    
std::vector<Task> TaskRepo::GetAllTasksForBoard(int boardId)
{
    if (_dr->Connected())
        std::runtime_error("Database is unavailable");
    auto answer = _dr->Exec("SELECT * FROM task WHERE board_id =" + std::to_string(boardId)+";"); 
    std::vector<Task> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationTask(data));
    }
    
    return res;
}

bool TaskRepo::ChangeTaskStatus(TaskStatus status, int taskId)
{
    if (_dr->Connected())
        return false;
    _dr->Exec("UPDATE task SET status=" + std::to_string(static_cast<int>(status)) + " WHERE id=" + std::to_string(taskId)+";");

    return true;
}

bool TaskRepo::DeleteTask(int taskId)
{
    if (_dr->Connected())
        return false;

    _dr->Exec("DELETE FROM task WHERE id=" + std::to_string(taskId)+";");	

    return true;
}