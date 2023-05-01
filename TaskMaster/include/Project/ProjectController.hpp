#pragma once
#include <vector>
#include <string>
#include <memory>
#include "ProjectHandlerInterface.hpp"
#include "BoardRepoInterface.hpp"
#include "ProjectRepoInterface.hpp"
#include "User.hpp"
#include "Project.hpp"
#include "Board.hpp"

using IProjectRepoUptr = std::unique_ptr<ProjectRepoInterface>;
using IBoardRepoUptr = std::unique_ptr<BoardRepoInterface>;

class ProjectController : ProjectHandlerInterface
{
public:
    ProjectController(IProjectRepoUptr projectRepo, IBoardRepoUptr boardRepo);
    ~ProjectController();
    void CreateBoard(int projectId, const std::string &boardName) override;
    std::string GetInviteLink(int projectId, int userId) override;
    std::vector<User> GetAllUsers(int projectId, int userId) override;
    std::vector<Board> GetAllBoards(int projectId) override;

private:
    IProjectRepoUptr _projectRepo;
    IBoardRepoUptr _boardRepo;
};