#pragma once
#include <string>
#include <memory>
#include "User.hpp"
#include "Task.hpp"
#include "TaskHandlerInterface.hpp"
#include "TaskRepoInterface.hpp"

using TRepoUPtr = std::unique_ptr<TaskRepoInterface>;

class TaskController : public TaskHandlerInterface
{
public:
    TaskController(TRepoUPtr repo): _repo(std::move(repo)) {}
    
    bool EditTask(const Task& newTask) override;
    bool CreateTask(const Task& Task) override;
    virtual bool DeleteTask(int taskId) override;

    ~TaskController();

private:
    TRepoUPtr _repo;
};