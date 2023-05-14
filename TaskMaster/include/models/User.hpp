#pragma once
#include <string>

class User
{
private:
public:
    User();
    User(const std::string &userName);
    User(const std::string &firstName, const std::string &lastName, 
         const std::string &userName, size_t companyId, const std::string &post);
    size_t Id;
    std::string FirstName;
    std::string LastName;
    std::string UserName;
    size_t CompanyId;
    std::string Post;
};
