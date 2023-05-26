#include "ProjectPage.h"
#include "BoardListItem.h"

#include <Wt/WDialog.h>
#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WDialog.h>
#include <Wt/WEnvironment.h>
#include <Wt/WLabel.h>
#include <Wt/WLineEdit.h>
#include <Wt/WTextArea.h>
#include <Wt/WPushButton.h>
#include <Wt/WRegExpValidator.h>
#include <Wt/WText.h>

ProjectPage::ProjectPage(Session& session, const Project& proj):session_(session), proj_(proj)
{
    if( session_.user().Id == proj.CreatorId ){
        setTemplateText(tr("project-page-admin"));
        bindAdmin();
    }else
        setTemplateText(tr("project-page"));
    this->bindString("projectName", proj.Name);
    this->bindString("description", proj.Description);
    createButton_ = this->bindWidget("createBoardButton", std::make_unique<Wt::WPushButton>("Create board"));
    createButton_->clicked().connect(this, &ProjectPage::createBoard);
    createButton_->addStyleClass("btn btn-success");
    boardsListWidget_ = this->bindWidget("boards", std::make_unique<Wt::WContainerWidget>());
    boards_ = session_.projectController().GetAllBoards(proj.Id);
    user_ = session.user();  //добавить в сесстию кеширование юзера
    showBoards();
}

void ProjectPage::bindAdmin()
{
    usersDropDown_ = this->bindWidget("usersList", std::make_unique<Wt::WComboBox>());
    userStringModel_ = std::make_shared<Wt::WStringListModel>();
    auto users = session_.userController().GetUsersNotInProject(proj_.Id);
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

void ProjectPage::createBoard()
{
    Wt::WDialog *dialog = this->addChild(std::make_unique<Wt::WDialog>("Create new boatd"));

    Wt::WLabel *titleLabel = dialog->contents()->addNew<Wt::WLabel>("Board title");
    Wt::WLineEdit *titleEdit = dialog->contents()->addNew<Wt::WLineEdit>();
    Wt::WLabel *descriptionLabel = dialog->contents()->addNew<Wt::WLabel>("Description");
    Wt::WTextArea *descriptionEdit = dialog->contents()->addNew<Wt::WTextArea>();

    titleLabel->setBuddy(titleEdit);
    descriptionLabel->setBuddy(descriptionEdit);

    dialog->contents()->addStyleClass("form-group");

    auto validator = std::make_shared<Wt::WRegExpValidator>("^(?!\\s*$).+");
    validator->setMandatory(true);
    titleEdit->setValidator(validator);
    descriptionEdit->setValidator(validator);

    Wt::WPushButton *ok =
        dialog->footer()->addNew<Wt::WPushButton>("Create");
    ok->addStyleClass("btn");
    ok->addStyleClass("btn-secondary");
    ok->setDefault(true);
    if (wApp->environment().ajax())
        ok->disable();

    Wt::WPushButton *cancel =
        dialog->footer()->addNew<Wt::WPushButton>("Cancel");
    cancel->addStyleClass("btn");
    cancel->addStyleClass("btn");
    dialog->rejectWhenEscapePressed();

    titleEdit->keyWentUp().connect([=] {
        ok->setDisabled(titleEdit->validate() != Wt::ValidationState::Valid);
    });

    descriptionEdit->keyWentUp().connect([=] {
        ok->setDisabled(descriptionEdit->validate() != Wt::ValidationState::Valid);
    });

    ok->clicked().connect([=] {
        if (titleEdit->validate() == Wt::ValidationState::Valid && descriptionEdit->validate() == Wt::ValidationState::Valid)
            dialog->accept();
    });

    cancel->clicked().connect(dialog, &Wt::WDialog::reject);

    dialog->finished().connect([=] {
        if (dialog->result() == Wt::DialogCode::Accepted) {
            if (titleEdit->validate() == Wt::ValidationState::Valid && descriptionEdit->validate() == Wt::ValidationState::Valid) {
                int id = session_.user().Id;
                auto name = titleEdit->text().toUTF8();
                auto text = descriptionEdit->text().toUTF8();
                Board newBoard = session_.projectController().CreateBoard(proj_.Id, id, name, text);
                showBoard(newBoard);
            }
        }
        this->removeChild(dialog);
    });

    dialog->show();
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