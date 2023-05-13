#pragma once
#include <string>

class User
{
private:
public:
    User();
    User(const std::string &userName);
    size_t Id;
    std::string FirstName;
    std::string LastName;
    std::string UserName;
    size_t CompanyId;
    std::string Post;
};
