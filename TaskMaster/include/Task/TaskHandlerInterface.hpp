#pragma once
#include <string>
#include "User.hpp"
#include "Task.hpp"

class TaskHandlerInterface
{
public:
    virtual ~TaskHandlerInterface() {}
    bool virtual EditTask(Task newTask) = 0;
    bool virtual CreateTask(std::string name, User user, std::string description) = 0;
};
