#pragma once
#include <vector>
#include "Board.hpp"
#include "Task.hpp"
#include "Project.hpp"
#include "User.hpp"

class BoardRepoInterface
{
public:
    virtual ~BoardRepoInterface() { }
    virtual std::vector<Board> GetAllBoardsForProject(int projectId) = 0;
    virtual bool CreateBoard(const Board& board) = 0;
    virtual bool DeleteBoard(int boardId) = 0;
};