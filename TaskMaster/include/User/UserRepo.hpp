#pragma once
#include <string>
#include <vector>
#include <memory>
#include "UserRepoInterface.hpp"
#include "DbDriverInterface.hpp"
#include "User.hpp"
#include "Task.hpp"
#include "Board.hpp"

using DbDriverSPtr = std::shared_ptr<DbDriverInterface>;

class UserRepo : public UserRepoInterface
{
public:
    User GetUser(int userId) override;
    User GetUserByIdentity(int userIdentityId) override;
    bool CreateUserWithIdentity(int userIdentityId) override;
    ~UserRepo() {}

private:
    DbDriverSPtr _dr;
};
