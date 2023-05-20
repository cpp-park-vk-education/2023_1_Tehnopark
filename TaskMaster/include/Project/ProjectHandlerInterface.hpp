#pragma once
#include <vector>
#include <string>
#include "User.hpp"
#include "Project.hpp"
#include "Board.hpp"

class ProjectHandlerInterface
{
public:
    virtual ~ProjectHandlerInterface() {}
    virtual void CreateBoard(int projectId, int creatorId, const std::string &boardName, const std::string &text) = 0;
    virtual void AddUser(int userId, int projectId) = 0;
    virtual std::vector<User> GetAllUsers(int projectId) = 0;
    virtual std::vector<Board> GetAllBoards(int projectId) = 0;
    virtual Board GetBoard(int boardId) = 0;
};