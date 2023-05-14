#pragma once
#include "BoardHandlerInterface.hpp"
#include "BoardRepoInterface.hpp"
#include "TaskRepoInterface.hpp"
#include <memory>

using ITaskRepoUptr = std::unique_ptr<TaskRepoInterface>;

class BoardController : public BoardHandlerInterface
{
public:
    ~BoardController() { }
    BoardController(ITaskRepoUptr taskRepo): _taskRepo(std::move(taskRepo)) { }
    bool AddTask(int projectId, int boardId,
                 const std::string& taskName, const std::string &text) override { return true;};
    void DeleteTask(int taskId) override;
    void ChangeTaskStatus(int taskId, TaskStatus status) override;
    void GetAllTasksForBoard(int boardId) override;
private:
    ITaskRepoUptr _taskRepo;
};