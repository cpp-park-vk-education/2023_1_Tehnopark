#pragma once
#include <string>

class Project
{
public:
    Project(int creatorId, const std::string &projectName);
    int CreatorId;
    std::string ProjectName;
};