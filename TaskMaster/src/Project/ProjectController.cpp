#include "ProjectController.hpp"

ProjectController::ProjectController(IProjectRepoUptr projectRepo, IBoardRepoUptr boardRepo, IUserRepoUptr userRepo) : 
    projectRepo_(std::move(projectRepo)), boardRepo_(std::move(boardRepo)), userRepo_(std::move(userRepo)) {}
ProjectController::~ProjectController() {}

void ProjectController::CreateBoard(int projectId, int creatorId, const std::string &boardName)
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