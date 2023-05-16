#include "TaskController.hpp"

bool TaskController::EditTask(const Task& newTask) 
{
    return _repo->EditTask(newTask);
}

bool TaskController::CreateTask(const Task& Task) 
{
    return _repo->CreateTask(Task);
}

bool TaskController::DeleteTask(int taskId)
{
    return _repo->DeleteTask(taskId);
}