#pragma once
#include <vector>
#include "Board.hpp"
#include "Task.hpp"
#include "BoardRepoInterface.hpp"

class BoardRepo : BoardRepoInterface
{
public:
    BoardRepo() { }

    ~BoardRepo() { }

    std::vector<Board> GetAllTasksForCompany(int companyId) override;

    bool AddTaskToBoard(int boardId, Task task) override;

    bool DeleteTaskOnBoard(int taskId) override;
};