#include "MainPadgeController.hpp"

MainPadgeController::MainPadgeController(IProjectRepoUptr projectRepo) : projectRepo_(std::move(projectRepo)) {}

std::vector<Project> MainPadgeController::GetUserProjects(int userId)
{
    // проверка на валидность тут?
    return projectRepo_->GetUserProjects(userId);
}

Project MainPadgeController::GetProjectById(int projectId)
{
    return projectRepo_->GetProjectById(projectId);
}

bool MainPadgeController::CreateProject(int userId, const std::string &projectName)
{
    return projectRepo_->CreateProject(userId, projectName);
}
