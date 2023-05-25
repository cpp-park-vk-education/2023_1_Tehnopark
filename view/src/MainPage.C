#include "MainPage.h"

MainPage::MainPage(Session &session) : session_(session)
{
    setTemplateText(tr("main-page"));
    projects_ = this->bindWidget("projects", std::make_unique<Wt::WContainerWidget>());
    user_ = session.user();
    createButton_ = this->bindWidget("createProjectButton", std::make_unique<Wt::WPushButton>("createProject"));
    createButton_->addStyleClass("btn");
    createButton_->addStyleClass("btn-success");
    createButton_->clicked().connect(this, &MainPage::createProject);
    projectTitle_ = this->bindWidget("projectNameInput", std::make_unique<Wt::WLineEdit>());
    projectDescription_ = this->bindWidget("projectTextInput", std::make_unique<Wt::WLineEdit>());
    showProjects();
}

void MainPage::showProjects()
{
    auto projects = session_.mainPadgeController().GetUserProjects(user_.Id);
    for (auto proj : projects)
        showProject(proj);
}

void MainPage::createProject()
{
    int id = session_.user().Id;
    auto name = projectTitle_->text().toUTF8();
    auto text = projectDescription_->text().toUTF8();
    auto newProject = session_.mainPadgeController().CreateProject(id, name, text);
}

void MainPage::showProject(const Project &proj)
{
    projects_->addWidget(std::make_unique<ProjectListItem>(session_, proj));
}

void MainPage::renderTemplate(std::ostream &result)
{
    WTemplate::renderTemplate(result);
}