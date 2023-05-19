#pragma once
#include <string>
#include <vector>
#include "User.hpp"
#include "Task.hpp"
#include "Board.hpp"
#include "Project.hpp"

class UserRepoInterface
{
public:
    virtual User GetUser(int userId) = 0;
    virtual User GetUserByIdentity(int userIdentityId) = 0;
    virtual bool CreateUserWithIdentity(int userIdentityId) = 0;
};