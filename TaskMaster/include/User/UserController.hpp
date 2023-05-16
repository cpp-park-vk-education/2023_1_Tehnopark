#pragma once
#include <string>
#include <vector>
#include <memory>
#include "User.hpp"
#include "Task.hpp"
#include "Board.hpp"
#include "Project.hpp"
#include "UserHandlerInterface.hpp"
#include "UserRepoInterface.hpp"

using UserRepoUPtr = std::unique_ptr<UserRepoInterface>;

class UserController : public UserHandlerInterface
{
public:
    User GetUser(int userId) override;
    User GetUserByIdentity(int userIdentityId) override;
    bool CreateUserWithIdentity(int userIdentityId) override;
    ~UserController(){}
private:
    UserRepoUPtr _repo;
};