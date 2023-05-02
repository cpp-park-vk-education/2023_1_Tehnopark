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
    virtual std::string AddUser(int projectId, const std::string &userName) = 0;
    virtual std::vector<User> GetAllUsers(int projectId) = 0;
    virtual std::vector<Board> GetAllBoards(int projectId) = 0;
};