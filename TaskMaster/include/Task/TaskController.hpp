#pragma once
#include <string>
#include "TaskHandlerInterface.hpp"
#include "User.hpp"
#include "Task.hpp"

class TaskController : public TaskHandlerInterface
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