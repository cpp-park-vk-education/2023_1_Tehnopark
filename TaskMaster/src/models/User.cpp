#include "User.hpp"

User::User(const std::string &userName) :
    UserName(userName) {}

User::User(const std::string &firstName, const std::string &lastName, 
         const std::string &userName, size_t companyId, const std::string &post) :
         FirstName(firstName), LastName(lastName), UserName(userName), CompanyId(companyId), Post(post) { }

User::User(){}