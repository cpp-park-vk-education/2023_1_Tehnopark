#pragma once
#include <string>
#include "User.hpp"
#include "Task.hpp"

class ITaskHandler
{
public:
    virtual ~ITaskHandler() {}
    bool virtual EditTask(Task newTask) = 0;
    bool virtual CreateTask(std::string name, User user, std::string description) = 0;
};
