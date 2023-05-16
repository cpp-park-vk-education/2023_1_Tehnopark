#include "MainPage.h"

MainPage::MainPage(Session& session):session_(session)
{
    setTemplateText(tr("main-page"));
    projects_ = this->bindWidget("projects", std::make_unique<Wt::WContainerWidget>());
    user_ = session.user();
}

void MainPage::showProjects()
{
    auto projects = session_.mainPadgeController().GetUserProjects(user_.Id);
    for(auto proj : projects)
        showProject(proj);
}

void MainPage::showProject(const Project& proj)
{
    projects_->addWidget(std::make_unique<ProjectListItem>(session_, proj));
}


void MainPage::renderTemplate(std::ostream& result)
{
    WTemplate::renderTemplate(result);
}