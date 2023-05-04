#pragma once
#include <string>

class Project
{
public:
    Project(int creatorId, const std::string &projectName);
    size_t Id;
    size_t CreatorId;
    std::string ProjectName;
};