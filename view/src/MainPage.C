#include "MainPage.h"


MainPage::MainPage(Session& session):session_(session)
{
    setTemplateText(tr("main-page"));
    projects_ = this->bindWidget("projects", std::make_unique<Wt::WContainerWidget>());
    user_ = session.user();
    
}