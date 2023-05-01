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
    virtual void CreateBoard(int projectId, const std::string &boardName) = 0;
    virtual std::string GetInviteLink(int projectId, int userId) = 0;
    virtual std::vector<User> GetAllUsers(int projectId, int userId) = 0;
    virtual std::vector<Board> GetAllBoards(int projectId) = 0;
};