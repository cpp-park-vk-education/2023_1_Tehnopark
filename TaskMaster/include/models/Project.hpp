#pragma once
#include <string>

class Project
{
public:
    Project(int creatorId, const std::string &projectName);

private:
    int _creatorId;
    std::string _projectName;
};