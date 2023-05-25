#pragma once
#include <string>
#include "User.hpp"
#include "Task.hpp"

class TaskHandlerInterface
{
public:
    virtual ~TaskHandlerInterface() {}
    virtual bool EditTask(const Task& newTask) = 0;
    virtual Task CreateTask(const Task& Task) = 0;
    virtual bool DeleteTask(int taskId) = 0;
};
