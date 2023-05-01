#pragma once
#include <vector>
#include "Board.hpp"
#include "Task.hpp"

class BoardRepoInterface
{
public:
    virtual ~BoardRepoInterface() { }

    virtual std::vector<Board> GetAllTasksForCompany(int companyId) = 0;

    virtual bool CreateBoard(int projectId, std::string name) = 0;

    virtual bool DeleteBoard(int boardId) = 0;
};