#include "TaskRepo.hpp"
#include "Serialization.hpp"

bool TaskRepo::EditTask(const Task& newTask)
{
    _dr->Exec("UPDATE db_task SET name=" + newTask.Name 
                + ", text=" + newTask.Text  
                + ", status=" + std::to_string(newTask.Status) 
                + ", board_id=" + std::to_string(newTask.BoardId)
                + ", due_date=" + newTask.DueDate + "WHERE id=" + std::to_string(newTask.Id));
    return true;
}
    
bool TaskRepo::CreateTask(const Task& Task)
{
    _dr->Exec("INSERT INTO db_task (board_id, name, text) VALUES (" + std::to_string(Task.BoardId) + Task.Name + Task.Text + ")");
    return true;
}
    
std::vector<Task> TaskRepo::GetAllTasksForBoard(int boardId)
{
    auto answer = _dr->Exec("SELECT * FROM db_task WHERE id =" + std::to_string(boardId)); 
    std::vector<Task> res;
    
    for (const auto &data : answer)
    {
        res.push_back(serializationTask(data));
    }
    
    return res;
}

bool TaskRepo::ChangeTaskStatus(TaskStatus status, int taskId)
{
    _dr->Exec("UPDATE db_task SET status=" + std::to_string(status) + "WHERE id=" + std::to_string(taskId));
    return true;
}

bool TaskRepo::DeleteTask(int taskId)
{
    _dr->Exec("DELETE FROM db_task WHERE id = " + std::to_string(2));	
    return true;
}