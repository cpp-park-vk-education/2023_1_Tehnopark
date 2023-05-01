#pragma once
#include "BoardHandlerInterface.hpp"
#include "BoardRepoInterface.hpp"
#include "TaskRepoInterface.hpp"

class BoardController : BoardHandlerInterface
{
public:
    BoardController(BoardRepoInterface boardRepo, TaskRepoInterface taskRepo): 
                    _boardRepo(boardRepo), _taskRepo(taskRepo) { }

    ~BoardController() { }

    std::vector<Board> GetAllTasksForCompany(int companyId) override;

    bool AddTaskToBoard(int boardId, Task task) override;

    bool DeleteTaskOnBoard(int taskId) override;

private:
    BoardRepoInterface _boardRepo;

    TaskRepoInterface _taskRepo;
}