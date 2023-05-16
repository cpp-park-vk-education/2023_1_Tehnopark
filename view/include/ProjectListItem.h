#pragma once

#include <Wt/WTemplate.h>


#include "Session.h"

namespace Wt {
  class WText;
}

class ProjectListItem : public Wt::WTemplate
{
public:
  ProjectListItem(Session& session, const Project& proj);

protected:
  virtual void renderTemplate(std::ostream& result);

private:
  Session& session_;
  Project project_;

  using WWebWidget::render;
};