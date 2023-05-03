#include "ProjectController.hpp"

ProjectController::ProjectController(IProjectRepoUptr projectRepo, IBoardRepoUptr boardRepo) : _projectRepo(std::move(projectRepo)), _boardRepo(std::move(boardRepo)) {}
ProjectController::~ProjectController() {}

void ProjectController::CreateBoard(int projectId, const std::string &boardName)
{
}
void ProjectController::AddUser(int projectId, const std::string &userName)
{
}
std::vector<User> ProjectController::GetAllUsers(int projectId)
{
    return std::vector<User>{};
}
std::vector<Board> ProjectController::GetAllBoards(int projectId)
{
    return std::vector<Board>{};
}