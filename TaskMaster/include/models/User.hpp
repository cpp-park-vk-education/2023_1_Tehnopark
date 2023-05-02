#pragma once
#include <string>

class User
{
public:
    User(const std::string &userName);

private:
    std::string _userName;
};
