#include "BoardListItem.h"

#include <Wt/WAnchor.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTextArea.h>

BoardListItem::BoardListItem(Session& session, const Board& board) : session_(session), board_(board)
{
    setTemplateText(tr("board"));

    this->bindWidget("title" ,std::make_unique<Wt::WAnchor>(Wt::WLink(Wt::LinkType::InternalPath, "/board/" + std::to_string(board.Id)), board.Name));

    this->bindWidget("description", std::make_unique<Wt::WText>(board.Text));

    this->bindWidget("creator", std::make_unique<Wt::WText>(session_.userController().GetUser(board.CreatorId).UserName));
}


void BoardListItem::renderTemplate(std::ostream& result)
{
    WTemplate::renderTemplate(result);
}