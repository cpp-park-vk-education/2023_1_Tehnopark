#include "ProjectController.hpp"

ProjectController::ProjectController(IProjectRepoUptr projectRepo, IBoardRepoUptr boardRepo, IUserRepoUptr userRepo) : 
    projectRepo_(std::move(projectRepo)), boardRepo_(std::move(boardRepo)), userRepo_(std::move(userRepo)) {}
ProjectController::~ProjectController() {}

void ProjectController::CreateBoard(size_t projectId, size_t creatorId, const std::string &boardName)
{
    boardRepo_->CreateBoard(projectId, creatorId, boardName, "");
}
void ProjectController::AddUser(size_t projectId, const std::string &userName)
{
    // userRepo_->AddProjectToUser()
}
std::vector<User> ProjectController::GetAllUsers(size_t projectId)
{
    return userRepo_->GetUsersForProject(projectRepo_->GetProjectById(projectId).Id);
}
std::vector<Board> ProjectController::GetAllBoards(size_t projectId)
{
    return boardRepo_->GetAllBoardsForProject(projectId);
}