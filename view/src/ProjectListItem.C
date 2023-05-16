#include "ProjectListItem.h"

#include <Wt/WAnchor.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTextArea.h>

ProjectListItem::ProjectListItem(Session& session, const Project& proj) : session_(session), project_(proj)
{
    setTemplateText(tr("project"));

    this->bindWidget("title" ,std::make_unique<Wt::WAnchor>(Wt::WLink(Wt::LinkType::InternalPath, "/project/" + std::to_string(proj.Id)), proj.Name));

    auto test = this->bindWidget("description", std::make_unique<Wt::WText>(proj.Description));
}


void ProjectListItem::renderTemplate(std::ostream& result)
{
    WTemplate::renderTemplate(result);
}