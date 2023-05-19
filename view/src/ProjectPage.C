#include "ProjectPage.h"

#include "BoardListItem.h"


ProjectPage::ProjectPage(Session& session, const Project& proj):session_(session)
{
    setTemplateText(tr("project-page"));
    this->bindString("projectName", proj.Name);
    this->bindString("description", proj.Description);
    
    boardsListWidget_ = this->bindWidget("boards", std::make_unique<Wt::WContainerWidget>());
    boards_ = session_.projectController().GetAllBoards(proj.Id);
    user_ = session.user();  //добавить в сесстию кеширование юзера
    showBoards();
}

void ProjectPage::showBoards()
{
    for(auto board : boards_)
        showBoard(board);
}

void ProjectPage::showBoard(const Board& board)
{
    boardsListWidget_->addWidget(std::make_unique<BoardListItem>(session_, board));
}


void ProjectPage::renderTemplate(std::ostream& result)
{
    WTemplate::renderTemplate(result);
}