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
    virtual void CreateBoard(size_t projectId, size_t creatorId, const std::string &boardName, const std::string &text) = 0;
    virtual void AddUser(size_t projectId, const std::string &userName) = 0;
    virtual std::vector<User> GetAllUsers(size_t projectId) = 0;
    virtual std::vector<Board> GetAllBoards(size_t projectId) = 0;
};