#pragma once
#include <vector>
#include <string>
#include "../models/User.hpp"
#include "../models/Project.hpp"
#include "../models/Board.hpp"

class ProjectHandlerInterface
{
public:
    virtual ~ProjectHandlerInterface() {}
    virtual void CreateBoard(int projectId, int mainUserId, const std::string &boardName) = 0;
    virtual std::string GetInviteLink(int projectId, int userId) = 0;
    virtual std::vector<User> GetAllUsers(int projectId, int userId) = 0;
    virtual std::vector<Board> GetAllBoards(int projectId, int userId) = 0;
};