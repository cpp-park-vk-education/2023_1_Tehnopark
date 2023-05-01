#include "ProjectController.hpp"

ProjectController::ProjectController(IProjectRepoUptr projectRepo, IBoardRepoUptr boardRepo) : _projectRepo(std::move(projectRepo)), _boardRepo(std::move(boardRepo)) {}
ProjectController::~ProjectController() {}

void ProjectController::CreateBoard(int projectId, const std::string &boardName)
{
}
std::string ProjectController::GetInviteLink(int projectId, int userId)
{
    return std::string{};
}
std::vector<User> ProjectController::GetAllUsers(int projectId, int userId)
{
    return std::vector<User>{};
}
std::vector<Board> ProjectController::GetAllBoards(int projectId)
{
    return std::vector<Board>{};
}