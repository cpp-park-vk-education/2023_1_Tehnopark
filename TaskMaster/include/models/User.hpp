#pragma once

class User
{
private:

public:
    std::string first_name;
    std::string last_name;
    std::string post;
    User(unsigned int id, const std::string &userName);
    ~User();
};


bool operator==(const User& a, const User& b){
    return a.first_name == b.first_name;
}