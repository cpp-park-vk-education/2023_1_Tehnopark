#include "BoardPage.h"

#include "TasksContainer.h"
#include "TaskListItem.h"

BoardPage::BoardPage(Session& session, const Board& board):session_(session), board_(board), dragStatus(false)
{
    setTemplateText(tr("board-page"));
    this->bindString("boardName", board.Name);
    this->bindString("description", board.Text);
    this->bindWidget("creator", std::make_unique<Wt::WText>(session_.userController().GetUser(board.CreatorId).UserName));
    tasks_ = session_.boardController().GetAllTasksForBoard(board_.Id);
    dragChangeButton_ = this->bindWidget("unlockDrag", std::make_unique<Wt::WPushButton>("Enable Drag"));
    dragChangeButton_->addStyleClass("btn");
    dragChangeButton_->addStyleClass("btn-success");
    dragChangeButton_->clicked().connect(this, &BoardPage::ChangeDrag);

    openListWidget_ = this->bindWidget("openTasks", std::make_unique<TasksContainer>(TaskStatus::Open));
    progressListWidget_ = this->bindWidget("inProgressTasks", std::make_unique<TasksContainer>(TaskStatus::InProgress));
    closedListWidget_ = this->bindWidget("closedTasks", std::make_unique<TasksContainer>(TaskStatus::Closed));
    showTasks();
}

void BoardPage::ChangeDrag()
{
    dragStatus = dragStatus ? false : true;
    if(dragStatus)
        dragChangeButton_->setText("Disable Drag");
    else
        dragChangeButton_->setText("Enable Drag");
    SetDrag(dragStatus);
}

void BoardPage::SetDrag(bool drag)
{
    for(auto c : openListWidget_->children())
    {
        auto child = static_cast<TaskListItem*>(c);
        if(drag)
            child->setDraggable("TaskListItem");
        else
            child->unsetDraggable();
    }
    for(auto c : progressListWidget_->children())
    {
        auto child = static_cast<TaskListItem*>(c);
        if(drag)
            child->setDraggable("TaskListItem");
        else
            child->unsetDraggable();
    }
    for(auto c : closedListWidget_->children())
    {
        auto child = static_cast<TaskListItem*>(c);
        if(drag)
            child->setDraggable("TaskListItem");
        else
            child->unsetDraggable();
    }
}

void BoardPage::showTasks()
{
    for(auto task : tasks_)
        showTask(task);
}

void BoardPage::showTask(const Task& task)
{
    switch (task.Status)
    {
    case TaskStatus::Open:
        openListWidget_->addWidget(std::make_unique<TaskListItem>(session_, task));
        break;
    case TaskStatus::InProgress:
        progressListWidget_->addWidget(std::make_unique<TaskListItem>(session_, task));
        break;
    case TaskStatus::Closed:
        closedListWidget_->addWidget(std::make_unique<TaskListItem>(session_, task));
        break;
    }
}


void BoardPage::renderTemplate(std::ostream& result)
{
    WTemplate::renderTemplate(result);
}