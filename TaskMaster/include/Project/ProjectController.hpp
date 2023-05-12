#pragma once
#include <vector>
#include <string>
#include <memory>
#include "ProjectHandlerInterface.hpp"
#include "BoardRepoInterface.hpp"
#include "ProjectRepoInterface.hpp"
#include "UserRepoInterface.hpp"
#include "User.hpp"
#include "Project.hpp"
#include "Board.hpp"

using IProjectRepoUptr = std::unique_ptr<ProjectRepoInterface>;
using IBoardRepoUptr = std::unique_ptr<BoardRepoInterface>;
using IUserRepoUptr = std::unique_ptr<UserRepoInterface>;

class ProjectController : public ProjectHandlerInterface
{
public:
    ProjectController(IProjectRepoUptr projectRepo, IBoardRepoUptr boardRepo, IUserRepoUptr userRepo);
    ~ProjectController();
    void CreateBoard(size_t projectId, size_t creatorId, const std::string &boardName, const std::string &text) override;
    void AddUser(size_t projectId, const std::string &userName) override;
    std::vector<User> GetAllUsers(size_t projectId) override;
    std::vector<Board> GetAllBoards(size_t projectId) override;

private:
    IProjectRepoUptr projectRepo_;
    IBoardRepoUptr boardRepo_;
    IUserRepoUptr userRepo_;
};