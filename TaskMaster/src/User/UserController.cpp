#include "UserController.hpp"

User UserController::GetUser(int userId)
{
    return _repo->GetUser(userId);
}

User UserController::GetUserByIdentity(int userIdentityId)
{
    return _repo->GetUserByIdentity(userIdentityId);
}

bool UserController::CreateUserWithIdentity(int userIdentityId)
{
    return _repo->CreateUserWithIdentity(userIdentityId);
}
