#pragma once
#include <string>

class Project
{
private:
    
public:
    std::string name;
    Project(int mainUserId, const std::string &projectName);
    ~Project();
};

bool operator==(const Project& a, const Project& b){
    return true;
}