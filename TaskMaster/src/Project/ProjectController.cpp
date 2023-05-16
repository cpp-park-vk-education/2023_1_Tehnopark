#include "ProjectController.hpp"

ProjectController::ProjectController(IProjectRepoUptr projectRepo, IBoardRepoUptr boardRepo, IUserRepoUptr userRepo) : 
    projectRepo_(std::move(projectRepo)), boardRepo_(std::move(boardRepo)), userRepo_(std::move(userRepo)) {}
ProjectController::~ProjectController() {}

void ProjectController::CreateBoard(int projectId, int creatorId, const std::string &boardName, const std::string &text)
{
    boardRepo_->CreateBoard(projectId, creatorId, boardName, text);
}
void ProjectController::AddUser(int projectId, const std::string &userName)
{
    // userRepo_->AddProjectToUser()
}
std::vector<User> ProjectController::GetAllUsers(int projectId)
{
    return userRepo_->GetUsersForProject(projectRepo_->GetProjectById(projectId).Id);
}
std::vector<Board> ProjectController::GetAllBoards(int projectId)
{
    return boardRepo_->GetAllBoardsForProject(projectId);
}