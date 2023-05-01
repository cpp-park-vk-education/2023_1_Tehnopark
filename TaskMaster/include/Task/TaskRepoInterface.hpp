#pragma once
#include <string>
#include <vector>
#include "User.hpp"
#include "Task.hpp"

class TaskRepoInterface
{
public:
    virtual ~TaskRepoInterface() {}
    bool virtual EditTask(Task newTask) = 0;
    bool virtual CreateTask(std::string name, User user, std::string description) = 0;
    std::vector<Task> virtual GetAllTasksForBoard(int boardId) = 0;
    bool virtual ChangeTaskStatus(TaskStatus status, int taskId) = 0;
    bool virtual CreateTask(Task task) = 0;
    bool virtual DeleteTask(int taskId) = 0;
};