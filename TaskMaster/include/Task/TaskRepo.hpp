#pragma once
#include <string>
#include <vector>
#include "User.hpp"
#include "Task.hpp"

class TaskRepo: public TaskRepoInterface
{
public:
    ~TaskRepo() {}
    bool EditTask(Task newTask) override{return True;}
    bool CreateTask(std::string name, User user, std::string description) override{return True;}
    std::vector<Task> GetAllTasksForBoard(int boardId) override
    {
        std::vector<Task> res = {Task(1,1, "Wash dishes"), Task(2,1, "Wash dog")};
        return res;
    }

    bool ChangeTaskStatus(enum status, int taskId) override{return True;}
    bool DeleteTask(int taskId) override{return True;}
};