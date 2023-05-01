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

    bool CreateBoard(int projectId, std::string name) override;

    bool DeleteBoard(int boardId) override;
};