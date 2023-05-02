#pragma once
#include <string>
#include "User.hpp"
#include "Task.hpp"

class TaskHandlerInterface
{
public:
    virtual ~TaskHandlerInterface() {}
    virtual bool EditTask(const Task& newTask) = 0;
};
