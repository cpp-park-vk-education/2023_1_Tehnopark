#pragma once
#include "BoardHandlerInterface.hpp"
#include "BoardRepoInterface.hpp"
#include "TaskRepoInterface.hpp"
#include <memory>

using IBoardRepoUptr = std::unique_ptr<BoardRepoInterface>;
using ITaskRepoUptr = std::unique_ptr<TaskRepoInterface>;

class BoardController : BoardHandlerInterface
{
public:
    BoardController(IBoardRepoUptr boardRepo, ITaskRepoUptr taskRepo): 
                    _boardRepo(std::move(boardRepo)), _taskRepo(std::move(taskRepo)) { }

    ~BoardController() { }

    bool AddTask(int taskId) override { return true; }

    void DeleteTask(int taskId) override { }

    void ChangeTaskStatus(int taskId, TaskStatus status) override { }

private:
    IBoardRepoUptr _boardRepo;

    ITaskRepoUptr _taskRepo;
};