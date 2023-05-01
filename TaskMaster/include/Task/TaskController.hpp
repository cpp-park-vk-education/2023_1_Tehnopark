#pragma once
#include <string>
#include "User.hpp"
#include "Task.hpp"

class TaskController : public ITaskHandler
{
public:
    ~TaskController() {}
    bool EditTask(Task newTask) override
    {
        return true;
    }

    bool CreateTask(std::string name, User user, std::string description) override
    {
        return true;
    }

};