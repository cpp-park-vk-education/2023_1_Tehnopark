#pragma once
#include <vector>
#include "Board.hpp"
#include "Task.hpp"

class BoardRepoInterface
{
public:
    virtual ~BoardRepoInterface() { }

    virtual std::vector<Board> GetAllTasksForCompany(int companyId) = 0;

    virtual bool AddTaskToBoard(int boardId, Task task) = 0;

    virtual bool DeleteTaskOnBoard(int taskId) = 0;
};