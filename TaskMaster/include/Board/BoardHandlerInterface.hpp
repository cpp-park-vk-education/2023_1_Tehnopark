#pragma once
#include <string>
#include "Task.hpp"
#include "User.hpp"

class BoardHandlerInterface
{
public:
    virtual ~BoardHandlerInterface() { }
    virtual bool AddTask(int projectId, int boardId, const std::string& taskName) = 0;
    virtual void DeleteTask(int taskId) = 0;
    virtual void ChangeTaskStatus(int taskId, TaskStatus status) = 0;
    virtual void GetAllTasksForBoard(int boardId) = 0;
};