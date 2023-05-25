#include "ProjectPage.h"

#include "BoardListItem.h"


ProjectPage::ProjectPage(Session& session, const Project& proj):session_(session), proj_(proj)
{
    if( session_.user().Id == proj.CreatorId ){
        setTemplateText(tr("project-page-admin"));
        bindAdmin();
    }else
        setTemplateText(tr("project-page"));
    this->bindString("projectName", proj.Name);
    this->bindString("description", proj.Description);
    boardsListWidget_ = this->bindWidget("boards", std::make_unique<Wt::WContainerWidget>());
    boards_ = session_.projectController().GetAllBoards(proj.Id);
    user_ = session.user();  //добавить в сесстию кеширование юзера
    showBoards();
}

void ProjectPage::bindAdmin()
{
    usersDropDown_ = this->bindWidget("usersList", std::make_unique<Wt::WComboBox>());
    userStringModel_ = std::make_shared<Wt::WStringListModel>();
    auto users = session_.userController().GetUsers();
    for (size_t i = 0; i < users.size(); i++){
        userStringModel_->addString(users[i].UserName);
        userStringModel_->setData(i, 0, users[i].Id, Wt::ItemDataRole::User);
    }
    usersDropDown_->setNoSelectionEnabled(true);
    usersDropDown_->setModel(userStringModel_);
    auto inviteButton = this->bindWidget("inviveButton", std::make_unique<Wt::WPushButton>("Invite to project"));
    inviteButton->addStyleClass("btn");
    inviteButton->addStyleClass("btn-success");
    inviteButton->clicked().connect(this, &ProjectPage::addUser);
}

void ProjectPage::showBoards()
{
    for(auto board : boards_)
        showBoard(board);
}

void ProjectPage::addUser()
{
    auto ind = usersDropDown_->currentIndex();
    if(usersDropDown_->currentIndex() == -1) return;

    auto userId = (int)Wt::asNumber(userStringModel_->data(userStringModel_->index(usersDropDown_->currentIndex(), 0), Wt::ItemDataRole::User));
    session_.userController().AddProjectToUser(userId, proj_.Id);
    usersDropDown_->removeItem(usersDropDown_->currentIndex());
}

void ProjectPage::showBoard(const Board& board)
{
    boardsListWidget_->addWidget(std::make_unique<BoardListItem>(session_, board));
}


void ProjectPage::renderTemplate(std::ostream& result)
{
    WTemplate::renderTemplate(result);
}