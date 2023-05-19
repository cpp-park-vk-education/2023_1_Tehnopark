#pragma once

#include <Wt/WTemplate.h>

#include "Board.hpp"
#include "Session.h"

namespace Wt {
  class WText;
}

class BoardListItem : public Wt::WTemplate
{
public:
  BoardListItem(Session& session, const Board& board);

protected:
  virtual void renderTemplate(std::ostream& result);

private:
  Session& session_;
  Board board_;

  using WWebWidget::render;
};