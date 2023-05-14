#include "MainView.h"
#include <Wt/WAnchor.h>
#include <Wt/WApplication.h>
#include <Wt/WCheckBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WEnvironment.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WTemplate.h>
#include <Wt/WText.h>

#include <Wt/Auth/PasswordService.h>
#include <Wt/Auth/PasswordVerifier.h>

#include <Wt/Dbo/backend/Postgres.h>

#include "Session.h"
#include "LoginWidget.h"

namespace dbo = Wt::Dbo;

class ViewImpl : public Wt::WContainerWidget
{
public:
  ViewImpl(const std::string& basePath, dbo::SqlConnectionPool& connectionPool,
           std::shared_ptr<DbDriverInterface> mainDb, MainView *blogView)
    : basePath_(basePath),
      session_(connectionPool, mainDb),
      panel_(nullptr),
      mustLoginWarning_(nullptr),
      invalidUser_(nullptr),
      page_(nullptr)
  {
    Wt::WApplication *app = Wt::WApplication::instance();

    app->messageResourceBundle().use(Wt::WApplication::appRoot() + "templates");
    app->useStyleSheet("style.css");
    app->internalPathChanged().connect(this, &ViewImpl::handlePathChange);

    loginStatus_ = this->addWidget(std::make_unique<Wt::WTemplate>(tr("blog-login-status")));
    panel_ = this->addWidget(std::make_unique<Wt::WStackedWidget>());
    page_ = this->addWidget(std::make_unique<Wt::WContainerWidget>());

    session_.login().changed().connect(this, &ViewImpl::onUserChanged);

    auto loginWidget
        = std::make_unique<LoginWidget>(session_, basePath);
    loginWidget_ = loginWidget.get();
    loginWidget_->hide();

    auto loginLink = std::make_unique<Wt::WText>(tr("login"));
    auto lPtr = loginLink.get();
    loginLink->setStyleClass("link");
    loginLink->clicked().connect(loginWidget_, &WWidget::show);
    loginLink->clicked().connect(lPtr, &WWidget::hide);

    auto registerLink = std::make_unique<Wt::WText>(tr("Wt.Auth.register"));
    registerLink->setStyleClass("link");
    registerLink->clicked().connect(loginWidget_,
                                    &LoginWidget::registerNewUser);

    auto archiveLink
        = std::make_unique<Wt::WAnchor>(Wt::WLink(Wt::LinkType::InternalPath, basePath_ + "all"),
                                      tr("archive"));

    loginStatus_->bindWidget("login", std::move(loginWidget));
    loginStatus_->bindWidget("login-link", std::move(loginLink));
    loginStatus_->bindWidget("register-link", std::move(registerLink));
    loginStatus_->bindWidget("archive-link", std::move(archiveLink));

    onUserChanged();

    loginWidget_->processEnvironment();
  }

  void onUserChanged() {
    if (session_.login().loggedIn())
      loggedIn();
    else
      loggedOut();
  }

  Session& session() { return session_; }

  void setInternalBasePath(const std::string& basePath) {
    basePath_ = basePath;
    refresh();
  }

  ~ViewImpl() {
    clear();
  }

private:
  std::string basePath_;
  Session session_;
  LoginWidget *loginWidget_;

  Wt::WStackedWidget* panel_;
  Wt::WTemplate *mustLoginWarning_;
  Wt::WTemplate *invalidUser_;
  Wt::WTemplate *loginStatus_;
  WContainerWidget *page_;

  void logout() {
    session_.login().logout();
  }

  void loggedOut() {
    loginStatus_->bindEmpty("profile-link");
    loginStatus_->bindEmpty("author-panel-link");
    loginStatus_->bindEmpty("userlist-link");

    loginStatus_->resolveWidget("login")->hide();
    loginStatus_->resolveWidget("login-link")->show();
    loginStatus_->resolveWidget("register-link")->show();

    refresh();
    panel_->hide();
  }

  void loggedIn() {
    Wt::WApplication::instance()->changeSessionId();

    refresh();

    loginStatus_->resolveWidget("login")->show();
    loginStatus_->resolveWidget("login-link")->hide();
    loginStatus_->resolveWidget("register-link")->hide();

    auto profileLink = std::make_unique<Wt::WText>(tr("profile"));
    profileLink->setStyleClass("link");

    dbo::ptr<AuthUser> user = session().user();

    loginStatus_->bindWidget("profile-link", std::move(profileLink));

  }


  void refresh() {
    handlePathChange(Wt::WApplication::instance()->internalPath());
  }

  void handlePathChange(const std::string&) {
    Wt::WApplication *app = Wt::WApplication::instance();

    if (app->internalPathMatches(basePath_)) {
      
    }
  }

  bool checkLoggedIn()
  {
    if (session_.user()) return true;
    panel_->show();
    if (!mustLoginWarning_){
      mustLoginWarning_ =
        panel_->addWidget(std::make_unique<Wt::WTemplate>(tr("blog-mustlogin")));
    }
    panel_->setCurrentWidget(mustLoginWarning_);
    return false;
  }

};




MainView::MainView(const std::string& basePath, Wt::Dbo::SqlConnectionPool& db, std::shared_ptr<DbDriverInterface> mainDb)
  : WCompositeWidget(),
    userChanged_()
{
  impl_ = setImplementation(std::make_unique<ViewImpl>(basePath, db, mainDb, this));
}

void MainView::setInternalBasePath(const std::string& basePath)
{
  impl_->setInternalBasePath(basePath);
}


dbo::ptr<AuthUser> MainView::user()
{
  if (impl_->session().user())
    return impl_->session().user();
  else
    return dbo::ptr<AuthUser>();
}
