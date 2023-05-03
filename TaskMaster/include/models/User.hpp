#pragma once
#include <string>

class User
{
private:
    size_t _id;
public:
    User(const std::string &userName);
    std::string UserName;
};
