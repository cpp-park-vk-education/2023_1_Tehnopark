#include "TaskListItem.h"

#include <Wt/WAnchor.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTextArea.h>

TaskListItem::TaskListItem(Session& session, const Task& task) : 
    session_(session), 
    task_(task),
    editStatus_(false),
    new_(false)
{
    setTemplateText(tr("task-list-item"));

    titleLabel_ = this->bindWidget("title", std::make_unique<Wt::WText>(task.Name));
    titleEdit_ = this->bindWidget("nameInput", std::make_unique<WLineEdit>(task.Name));
    descriptionLabel_ = this->bindWidget("text", std::make_unique<Wt::WText>(task.Text));
    descriptionEdit_ = this->bindWidget("textInput", std::make_unique<WLineEdit>(task.Text));
    users_ = session_.userController().GetUsersForTask(task_.Id);
    usersListWidget_ = this->bindWidget("AssignedUsers", std::make_unique<WContainerWidget>());
    ShowUsers();
    cancelButton_ = this->bindWidget("cancelButton", std::make_unique<WPushButton>("cancel"));
    cancelButton_->addStyleClass("btn");
    cancelButton_->addStyleClass("btn-success");
    cancelButton_->clicked().connect(this, &TaskListItem::CancelBtnClicked);
    editButton_ = this->bindWidget("editButton", std::make_unique<WPushButton>("edit"));
    editButton_->addStyleClass("btn");
    editButton_->addStyleClass("btn-success");
    editButton_->clicked().connect(this, &TaskListItem::EditBtnClicked);
    titleEdit_->hide();
    descriptionEdit_->hide();
    cancelButton_->hide();
}

void TaskListItem::CancelBtnClicked()
{
    descriptionLabel_->show();
    titleLabel_->show();
    titleEdit_->hide();
    descriptionEdit_->hide();
    cancelButton_->hide();
    editButton_->setText("edit");
    editStatus_ = false;
}

void TaskListItem::EditBtnClicked()
{
    if(editStatus_){
        task_.Name = titleEdit_->text().toUTF8();
        task_.Text = descriptionEdit_->text().toUTF8();
        titleLabel_->setText(titleEdit_->text());
        descriptionLabel_->setText(descriptionEdit_->text());
        session_.taskController().EditTask(task_);
        CancelBtnClicked();
    }else{
        editButton_->setText("save");
        titleLabel_->hide();
        descriptionLabel_->hide();
        titleEdit_->show();
        descriptionEdit_->show();
        cancelButton_->show();
        editStatus_ = true;
    }
}

void TaskListItem::ShowUsers()
{
    usersListWidget_->clear();
    for(auto user : users_){
        auto widget = usersListWidget_->addWidget(std::make_unique<Wt::WTemplate>(tr("user-task-list-item")));
        widget->bindString("username", user.UserName);
    }
}

void TaskListItem::SetStatus(TaskStatus status)
{
    task_.Status = status;
    auto tmp = session_.boardController().ChangeTaskStatus(task_.Id, status);
}


void TaskListItem::renderTemplate(std::ostream& result)
{
    WTemplate::renderTemplate(result);
}