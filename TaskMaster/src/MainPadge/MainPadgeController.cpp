#include "MainPadgeController.hpp"

MainPadgeController::MainPadgeController(IProjectRepoUptr projectRepo) : projectRepo_(std::move(projectRepo)) {}

std::vector<Project> MainPadgeController::GetUserProjects(size_t userId)
{
    return projectRepo_->GetUserProjects(userId);
}

Project MainPadgeController::GetProjectById(size_t projectId)
{
    return projectRepo_->GetProjectById(projectId);
}

bool MainPadgeController::CreateProject(size_t userId, const std::string &projectName)
{
    return projectRepo_->CreateProject(userId, projectName);
}
