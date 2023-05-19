#include "UserRepo.hpp"
#include "Serialization.hpp"
#include <iostream>


User UserRepo::GetUser(int userId)
{
    if (!_dr->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = _dr->Exec("SELECT * FROM \"user\" WHERE id=" + std::to_string(userId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Users with userId=" + std::to_string(userId) + " not found");
    return serializationUser(answer[0]);
}

User UserRepo::GetUserByIdentity(int userIdentityId)
{
    if (!_dr->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = _dr->Exec("SELECT * FROM \"user\" WHERE auth_identity_id=" + std::to_string(userIdentityId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Users with auth_identity_id=" + std::to_string(userIdentityId) + " not found");
    return serializationUser(answer[0]);
}

bool UserRepo::CreateUserWithIdentity(int userIdentityId)
{
    if (!_dr->Connected())
        return false;
    _dr->Exec("INSERT INTO \"user\" (name, auth_identity_id) SELECT auth_identity.identity, auth_identity.id FROM auth_identity WHERE auth_identity.id =" + std::to_string(userIdentityId) + ";");
    return true;
}