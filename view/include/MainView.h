#pragma once

#include <Wt/WCompositeWidget.h>
#include "DbDriverInterface.hpp"
#include "AuthUser.h"

namespace Wt {
  class WContainerWidget;
}

class ViewImpl;

class MainView : public Wt::WCompositeWidget
{
public:
  MainView(const std::string& basePath, Wt::Dbo::SqlConnectionPool& db, std::shared_ptr<DbDriverInterface> mainDb);

  void setInternalBasePath(const std::string& basePath);

  const User& user();
  void login(const std::string& user);
  void logout();

  Wt::Signal<Wt::WString>& userChanged() { return userChanged_; }

private:
  ViewImpl *impl_;
  Wt::Signal<Wt::WString> userChanged_;
};
