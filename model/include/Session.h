#pragma once

#include <Wt/Auth/Login.h>
#include <Wt/Auth/Dbo/UserDatabase.h>

#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/ptr.h>
#include "DbDriverInterface.hpp"

#include "AuthUser.h"

namespace dbo = Wt::Dbo;

using UserDatabase = Wt::Auth::Dbo::UserDatabase<AuthInfo>;

/*
добавить сигналы смены 
*/

class Session : public dbo::Session
{
public:
  static void configureAuth();

  Session(dbo::SqlConnectionPool& connectionPool, std::shared_ptr<DbDriverInterface> mainDb);

  dbo::ptr<AuthUser> user() const;

  UserDatabase& users() { return users_; }
  Wt::Auth::Login& login() { return login_; }

  static const Wt::Auth::AuthService& auth();
  static const Wt::Auth::PasswordService& passwordAuth();

  static std::unique_ptr<dbo::SqlConnectionPool> createConnectionPool(const std::string& pgsql);

private:
  dbo::SqlConnectionPool&     connectionPool_;
  UserDatabase users_;
  Wt::Auth::Login login_;
};